#version 450 core

out vec4 color;

layout (location = 0) uniform vec4 u_Color;
layout (location = 1) uniform vec2 u_ScreenDimensions;
layout (location = 2) uniform vec3 u_SpherePosition;
layout (location = 3) uniform float u_SphereRadius;
layout (location = 4) uniform vec3 u_LightDirection;

struct Ray {
    vec3 origin;
    vec3 direction;
};

struct Sphere {
    vec3 position;
    float radius;
};

bool raySphereIntersection(const Ray ray, const Sphere sphere, out vec3 intersectionPoint) {
    vec3 oc = ray.origin - sphere.position;
    float a = dot(ray.direction, ray.direction);
    float b = 2.0 * dot(oc, ray.direction);
    float c = dot(oc, oc) - sphere.radius * sphere.radius;
    float discriminant = b * b - 4.0 * a * c;

    if (discriminant > 0.0) {
        float t = (-b - sqrt(discriminant)) / (2.0 * a);
        intersectionPoint = ray.origin + t * ray.direction;
        return true;
    }

    return false;
}

void main() {
    vec2 pixelCoord = gl_FragCoord.xy;

    float aspectRatio = u_ScreenDimensions.x / u_ScreenDimensions.y;
    vec2 normalizedCoord = pixelCoord / u_ScreenDimensions;
    normalizedCoord.x = (normalizedCoord.x - 0.5) * aspectRatio + 0.5;

    vec3 rayOrigin = vec3(0.0, 0.0, 0.0);
    vec3 rayDirection = normalize(vec3(normalizedCoord - 0.5, 1.0));

    Ray ray;
    ray.origin = rayOrigin;
    ray.direction = rayDirection;

    Sphere sphere;
    sphere.position = u_SpherePosition;
    sphere.radius = u_SphereRadius;

    vec3 intersectionPoint;
    if (raySphereIntersection(ray, sphere, intersectionPoint)) {
        vec3 normal = normalize(intersectionPoint - sphere.position);
        float diffuse = max(dot(normal, u_LightDirection), 0.0);
        color = u_Color * diffuse;
    } else {
        color = vec4(0.0, 0.0, 0.0, 1.0);
    }
}