/**
 * @file buffers.h
 * @brief Contains constant buffers
*/

#pragma once

#include "vec/mat.h"

/**
 * @brief Contains transformation matrices.
*/
struct TransformationBuffer
{
	linalg::mat4f ModelToWorldMatrix; //!< Matrix for converting from object space to world space.
	linalg::mat4f WorldToViewMatrix; //!< Matrix for converting from world space to view space.
	linalg::mat4f ProjectionMatrix; //!< Matrix for converting from view space to clip cpace.
};

struct alignas(16) LightCamBuffer
{
	alignas(16) vec4f Light_Position;
	alignas(16) vec4f Camera_Position;
};

struct alignas(16) MaterialBuffer 
{
	alignas(16) vec3f Ambient;
	alignas(16) vec3f Diffuse;
	alignas(16) vec4f Specular;
};
