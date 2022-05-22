#ifndef __COLLISION_OBJECT_H__
#define __COLLISION_OBJECT_H__

#include "rigid_body.h"
#include "collision.h"
#include "../math/box3d.h"

struct CollisionObject {
    struct ColliderTypeData *collider;
    struct RigidBody* body;
    struct Box3D boundingBox;
};

void collisionObjectInit(struct CollisionObject* object, struct ColliderTypeData *collider, struct RigidBody* body, float mass);

void collisionObjectCollideWithPlane(struct CollisionObject* object, struct CollisionObject* plane, struct ContactSolver* contactSolver);
void collisionObjectCollideWithQuad(struct CollisionObject* object, struct CollisionObject* quad, struct ContactSolver* contactSolver);

void collisionObjectUpdateBB(struct CollisionObject* object);

#endif