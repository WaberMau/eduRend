#include "Camera.h"
#include <iostream>

using namespace linalg;
mat4f RotationMatrix;

void Camera::MoveTo(const vec3f& position) noexcept
{
	m_position = position;
}

void Camera::Move(const vec4f& direction) noexcept
{

	mat4f C = RotationMatrix * mat4f::translation(m_position);

	vec4f viewDirection = C * direction;
	
	m_position += viewDirection.xyz();
	
}

mat4f Camera::WorldToViewMatrix(float dx, float dy) const noexcept
{
	// Assuming a camera's position and rotation is defined by matrices T(p) and R,
	// the View-to-World transform is T(p)*R (for a first-person style camera).
	//
	// World-to-View then is the inverse of T(p)*R;
	//		inverse(T(p)*R) = inverse(R)*inverse(T(p)) = transpose(R)*T(-p)
	// Since now there is no rotation, this matrix is simply T(-p)

	RotationMatrix = mat4f::rotation(0, -dx, -dy);
	mat4f R = RotationMatrix;
	R.transpose();
	return R * mat4f::translation(-m_position);
}

mat4f Camera::ProjectionMatrix() const noexcept
{
	return mat4f::projection(m_vertical_fov, m_aspect_ratio, m_near_plane, m_far_plane);
}