//
// Created by Göksu Güvendiren on 2019-05-14.
//

#include "Scene.hpp"


void Scene::buildBVH() {
    printf(" - Generating BVH...\n\n");
    this->bvh = new BVHAccel(objects, 1, BVHAccel::SplitMethod::NAIVE);
}

Intersection Scene::intersect(const Ray &ray) const
{
    return this->bvh->Intersect(ray);
}

void Scene::sampleLight(Intersection &pos, float &pdf) const
{
    float emit_area_sum = 0;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        if (objects[k]->hasEmit()){
            emit_area_sum += objects[k]->getArea();
        }
    }
    float p = get_random_float() * emit_area_sum;
    emit_area_sum = 0;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        if (objects[k]->hasEmit()){
            emit_area_sum += objects[k]->getArea();
            if (p <= emit_area_sum){
                objects[k]->Sample(pos, pdf);
                break;
            }
        }
    }
}

bool Scene::trace(
        const Ray &ray,
        const std::vector<Object*> &objects,
        float &tNear, uint32_t &index, Object **hitObject)
{
    *hitObject = nullptr;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        float tNearK = kInfinity;
        uint32_t indexK;
        Vector2f uvK;
        if (objects[k]->intersect(ray, tNearK, indexK) && tNearK < tNear) {
            *hitObject = objects[k];
            tNear = tNearK;
            index = indexK;
        }
    }


    return (*hitObject != nullptr);
}
static float minpdf = 1111;
static float maxpdf = 0.f;
// Implementation of Path Tracing
Vector3f Scene::castRay(const Ray &ray, int depth) const
{
    // TO DO Implement Path Tracing Algorithm here
    Intersection intersection = Scene::intersect(ray);
    Vector3f N = intersection.normal.normalized();
    Vector3f p = intersection.coords;
    Vector3f wo = ray.direction;

    Vector3f L_dir(0.f);
    Vector3f L_indir(0.f);
    if(intersection.happened)
    {
        if (intersection.m->hasEmission())
        {
            if (!depth)
                return intersection.m->getEmission();
            else
                return Vector3f(0.f);
        }
        
        float pdf_light;
        Intersection inter;
        sampleLight(inter, pdf_light);
        Vector3f x = inter.coords;
        Vector3f NN = inter.normal;
        Vector3f emit = inter.emit;
        Vector3f ws = normalize(x - p);
        float distance = (x - p).norm();

        Ray rayToLight(p, ws);
        Intersection interWithLight = Scene::intersect(rayToLight);
        if (interWithLight.happened && interWithLight.m->hasEmission())
        {
            L_dir = emit * intersection.m->eval(wo, ws, N)
            * dotProduct(ws, N) * dotProduct(-ws, NN)
            / distance / distance
            / pdf_light;
        }
        
        if (get_random_float() < RussianRoulette)
        {
            Vector3f wi = intersection.m->sample(wo, N).normalized();
            Ray rayToObj(p, wi);
            Intersection interWithObj = Scene::intersect(rayToObj);
            if (interWithObj.happened && !interWithObj.m->hasEmission())
            {
                float pdf = intersection.m->pdf(wo, wi, N);
                if (pdf > EPSILON)
                {                
                    L_indir = castRay(rayToObj, depth + 1) 
                    * intersection.m->eval(wo, wi, N) 
                    * dotProduct(wi, N) 
                    / pdf 
                    / RussianRoulette;
                }

            }
        }

        return L_dir + L_indir;
    }

    return this->backgroundColor;
}