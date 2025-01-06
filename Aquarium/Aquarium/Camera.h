
#pragma once

#include <GLM.hpp>

#include "Fish.h"

enum ECameraMovementType
{
	UNKNOWN,
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
enum CameraMode {
	FirstPerson,
	ThirdPerson,
	FreeLook
};
class Camera
{
private:
	// Default camera values
	const float zNEAR = 0.1f;
	const float zFAR = 500.f;
	const float YAW = -90.0f;
	const float PITCH = 0.0f;
	const float FOV = 45.0f;
	glm::vec3 startPosition;
	CameraMode mode = CameraMode::FreeLook;
public:
	Camera(const int width, const int height, const glm::vec3& position);

	glm::vec3 GetPosition();

	void Set(const int width, const int height, const glm::vec3& position);
	void Reset(const int width, const int height);
	void Reshape(int windowWidth, int windowHeight);

	glm::mat4 GetViewMatrix(Fish& fish);
	const glm::mat4 GetProjectionMatrix() const;

	void ProcessKeyboard(ECameraMovementType direction, double deltaTime);
	void MouseControl(float xPos, float yPos);
	void ProcessMouseScroll(float yOffset);
	void SetCameraMode(CameraMode mode);
	CameraMode GetCameraMode();
	void SetRotation(glm::vec3 rotation);
	glm::vec3 GetRotation();
	void SetPosition(const glm::vec3 vec);
	void SetYaw(float yaw);
	void SetPitch(float pitch);
	void SetRoll(float x);
private:
	void ProcessMouseMovement(float xOffset, float yOffset, bool constrainPitch = true);
	void UpdateCameraVectors();

protected:
	const float cameraSpeedFactor = 25.5f;
	const float mouseSensitivity = 0.1f;

	// Perspective properties
	float zNear;
	float zFar;
	float FoVy;
	int width;
	int height;
	bool isPerspective;

	glm::vec3 rotation;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 right;
	glm::vec3 up;
	glm::vec3 worldUp;

	// Euler Angles
	float yaw;
	float pitch;
	float roll;
	bool bFirstMouseMove = true;
	float lastX = 0.f, lastY = 0.f;
};