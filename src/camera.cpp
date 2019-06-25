//
//  Camera.cpp
//  OGL
//
//  Created by u0964759 on 6/10/19.
//  Copyright © 2019 u0964759. All rights reserved.
//

#include "camera.hpp"

Camera::Camera() {}

Camera::Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed)
{
    position = startPosition;
    worldUp = startUp;
    yaw = startYaw;
    pitch = startPitch;
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    
    moveSpeed = startMoveSpeed;
    turnSpeed = startTurnSpeed;
    
    update();
}

//key controls for camera, 6DOF style
void Camera::keyControl(bool* keys, GLfloat deltaTime)
{
    GLfloat velocity = moveSpeed * deltaTime;
    //forward movement
    if (keys[GLFW_KEY_W])
    {
        position += front * velocity;
    }
    //backwards movement
    if (keys[GLFW_KEY_S])
    {
        position -= front * velocity;
    }
    //left movement
    if (keys[GLFW_KEY_A])
    {
        position -= right * velocity;
    }
    //right movement
    if (keys[GLFW_KEY_D])
    {
        position += right * velocity;
    }
    //down movement
    if (keys[GLFW_KEY_E])
    {
        position -= up * velocity;
    }
    //up movement
    if (keys[GLFW_KEY_Q])
    {
        position += up * velocity;
    }
    //locks/unlocks camera look controls with mouse
    if (keys[GLFW_KEY_C])
    {
        cameraOn = !cameraOn;
        keys[GLFW_KEY_C] = false;
    }
}

//Mouse control for camera
void Camera::mouseControl(GLfloat xChange, GLfloat yChange)
{
    xChange *= turnSpeed;
    yChange *= turnSpeed;
    
    yaw += xChange;
    pitch += yChange;
    
    if (pitch > 89.0f)
    {
        pitch = 89.0f;
    }
    
    if (pitch < -89.0f)
    {
        pitch = -89.0f;
    }
    
    update();
}

//View matricx calculate
glm::mat4 Camera::calculateViewMatrix()
{
    return glm::lookAt(position, position + front, up);
}

//Getter for camera position
glm::vec3 Camera::getCameraPosition()
{
    return position;
}

//getter for camera direction
glm::vec3 Camera::getCameraDirection()
{
	return glm::normalize(front);
}

//Camera update loop
void Camera::update()
{
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(front);
    
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}


Camera::~Camera()
{
}
