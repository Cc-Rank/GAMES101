#include <iostream>
#include <vector>

#include "CGL/vector2D.h"

#include "mass.h"
#include "rope.h"
#include "spring.h"

namespace CGL {

    Rope::Rope(Vector2D start, Vector2D end, int num_nodes, float node_mass, float k, vector<int> pinned_nodes)
    {
        // TODO (Part 1): Create a rope starting at `start`, ending at `end`, and containing `num_nodes` nodes.

        // Comment-in this part when you implement the constructor
        Vector2D step = (end - start) / (num_nodes - 1);
        for (int i = 0; i < num_nodes; ++i)
        {
            Mass *temp_mass = new Mass(start + i * step, node_mass, false);
            masses.emplace_back(temp_mass);
            if (i)
            {
                Spring *temp_spring = new Spring(masses[i - 1], masses[i], k);
                springs.emplace_back(temp_spring);
            }
        }
        for (auto &i : pinned_nodes) {
            masses[i]->pinned = true;
        }
    }

    void Rope::simulateEuler(float delta_t, Vector2D gravity)
    {
        for (auto &s : springs)
        {
            // TODO (Part 2): Use Hooke's law to calculate the force on a node
            Vector2D diff_vector = s->m2->position - s->m1->position;
            Vector2D force = -s->k * diff_vector.unit() * (diff_vector.norm() - s->rest_length);
            s->m2->forces += force;
            s->m1->forces += -force;
        }

        for (auto &m : masses)
        {
            if (!m->pinned)
            {
                // TODO (Part 2): Add global damping
                // TODO (Part 2): Add the force due to gravity, then compute the new velocity and position
                m->forces += m->mass * gravity;
                m->forces += -0.01f * m->velocity;
                Vector2D acceleration = m->forces / m->mass;
                // // For explicit method
                // m->position = m->position + m->velocity * delta_t;
                // m->velocity = m->velocity + acceleration * delta_t;
                // For semi-implicit method
                m->velocity = m->velocity + acceleration * delta_t;
                m->position = m->position + m->velocity * delta_t;
            }

            // Reset all forces on each mass
            m->forces = Vector2D(0, 0);
        }
    }

    void Rope::simulateVerlet(float delta_t, Vector2D gravity)
    {
        for (auto &s : springs)
        {
            // // TODO (Part 3): Simulate one timestep of the rope using explicit Verlet （solving constraints)
            Vector2D diff_vector = s->m2->position - s->m1->position;
            Vector2D force = -s->k * diff_vector.unit() * (diff_vector.norm() - s->rest_length);
            s->m2->forces += force;
            s->m1->forces += -force;
        }

        for (auto &m : masses)
        {
            if (!m->pinned)
            {
                Vector2D temp_position = m->position;
                // TODO (Part 3.1): Set the new position of the rope mass
                // TODO (Part 4): Add global Verlet damping
                float damping_factor = 0.00005f;
                m->forces += m->mass * gravity;
                Vector2D acceleration = m->forces / m->mass;
                m->position = temp_position + (1 - damping_factor) * (temp_position - m->last_position) + acceleration * delta_t * delta_t;
                m->last_position = temp_position;
            }            
            // Reset all forces on each mass
            m->forces = Vector2D(0, 0);
        }
    }
}
