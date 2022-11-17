#include <algorithm>
#include <cassert>
#include "BVH.hpp"

BVHAccel::BVHAccel(std::vector<Object*> p, int maxPrimsInNode,
                   SplitMethod splitMethod)
    : maxPrimsInNode(std::min(255, maxPrimsInNode)), splitMethod(splitMethod),
      primitives(std::move(p))
{
    time_t start, stop;
    time(&start);
    if (primitives.empty())
        return;
        
    root = recursiveBuild(primitives);

    time(&stop);
    double diff = difftime(stop, start);
    int hrs = (int)diff / 3600;
    int mins = ((int)diff / 60) - (hrs * 60);
    int secs = (int)diff - (hrs * 3600) - (mins * 60);

    printf(
        "\rBVH Generation complete: \nTime Taken: %i hrs, %i mins, %i secs\n\n",
        hrs, mins, secs);
}

BVHBuildNode* BVHAccel::recursiveBuild(std::vector<Object*> objects)
{
    BVHBuildNode* node = new BVHBuildNode();

    // Compute bounds of all primitives in BVH node
    Bounds3 bounds;
    for (int i = 0; i < objects.size(); ++i)
        bounds = Union(bounds, objects[i]->getBounds());
    if (objects.size() == 1) {
        // Create leaf _BVHBuildNode_
        node->bounds = objects[0]->getBounds();
        node->object = objects[0];
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }
    else if (objects.size() == 2) {
        node->left = recursiveBuild(std::vector{objects[0]});
        node->right = recursiveBuild(std::vector{objects[1]});

        node->bounds = Union(node->left->bounds, node->right->bounds);
        return node;
    }
    else {
        Bounds3 centroidBounds;
        for (int i = 0; i < objects.size(); ++i)
            centroidBounds =
                Union(centroidBounds, objects[i]->getBounds().Centroid());
        int dim = centroidBounds.maxExtent();
        switch (dim) {
        case 0:
            std::sort(objects.begin(), objects.end(), [](auto f1, auto f2) {
                return f1->getBounds().Centroid().x <
                       f2->getBounds().Centroid().x;
            });
            break;
        case 1:
            std::sort(objects.begin(), objects.end(), [](auto f1, auto f2) {
                return f1->getBounds().Centroid().y <
                       f2->getBounds().Centroid().y;
            });
            break;
        case 2:
            std::sort(objects.begin(), objects.end(), [](auto f1, auto f2) {
                return f1->getBounds().Centroid().z <
                       f2->getBounds().Centroid().z;
            });
            break;
        }
        
        if (splitMethod == SplitMethod::NAIVE)
        {
            auto beginning = objects.begin();
            auto middling = objects.begin() + (objects.size() / 2);
            auto ending = objects.end();

            auto leftshapes = std::vector<Object*>(beginning, middling);
            auto rightshapes = std::vector<Object*>(middling, ending);

            assert(objects.size() == (leftshapes.size() + rightshapes.size()));

            node->left = recursiveBuild(leftshapes);
            node->right = recursiveBuild(rightshapes);

            node->bounds = Union(node->left->bounds, node->right->bounds);
        }
        else if (splitMethod == SplitMethod::SAH)
        {
            int C_trav = 0, C_isect = 1;
            double min_cost = std::numeric_limits<float>::max();

            auto beginning = objects.begin();
            auto ending = objects.end();
            int splitIndex;
            for (int i = 1; i < objects.size() - 1; ++i)
            {
                auto middling = objects.begin() + i;

                auto leftshapes = std::vector<Object*>(beginning, middling);
                auto rightshapes = std::vector<Object*>(middling, ending);

                assert(objects.size() == (leftshapes.size() + rightshapes.size()));

                double S_a = 0, S_b = 0;
                for (auto left_it = leftshapes.begin(); left_it != leftshapes.end(); ++left_it)
                {
                    node->bounds = Union(node->bounds, (*left_it)->getBounds());
                    S_a += (*left_it)->getBounds().SurfaceArea();
                }
                for (auto right_it = rightshapes.begin(); right_it != rightshapes.end(); ++right_it)
                {
                    node->bounds = Union(node->bounds, (*right_it)->getBounds());
                    S_b += (*right_it)->getBounds().SurfaceArea();
                }
                double inverse_S_n = 1 / node->bounds.SurfaceArea();

                int N_a = leftshapes.size();
                int N_b = rightshapes.size();
                
                double cost = C_trav + S_a * inverse_S_n * N_a * C_isect + S_b *inverse_S_n * N_b * C_isect;
                if (cost < min_cost)
                {
                    min_cost = cost;
                    splitIndex = i;
                }
            }

            auto middling =  objects.begin() + splitIndex;

            auto leftshapes = std::vector<Object*>(beginning, middling);
            auto rightshapes = std::vector<Object*>(middling, ending);

            assert(objects.size() == (leftshapes.size() + rightshapes.size()));

            node->left = recursiveBuild(leftshapes);
            node->right = recursiveBuild(rightshapes);

            node->bounds = Union(node->left->bounds, node->right->bounds);
        }

    }

    return node;
}

Intersection BVHAccel::Intersect(const Ray& ray) const
{
    Intersection isect;
    if (!root)
        return isect;
    isect = BVHAccel::getIntersection(root, ray);
    return isect;
}

Intersection BVHAccel::getIntersection(BVHBuildNode* node, const Ray& ray) const
{
    // TODO Traverse the BVH to find intersection
    Intersection isect;
    std::array<int, 3> dirIsNeg = {int(ray.direction.x>0),int(ray.direction.y>0),int(ray.direction.z>0)};
    
    if (!node->bounds.IntersectP(ray, ray.direction_inv, dirIsNeg))
        return isect;
    
    if (node->object)
        return node->object->getIntersection(ray);

    Intersection isect1, isect2;
    isect1 = getIntersection(node->left, ray);
    isect2 = getIntersection(node->right, ray);
    
    if (isect1.distance < isect2.distance)    
        return isect1;
    else
        return isect2;
}