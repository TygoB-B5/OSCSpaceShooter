#include "DebugController.h"

namespace Input
{
	DebugController::DebugController()
	{
		Setup();
	}

	void DebugController::Setup()
	{
		ResetAcceleration();
	}

	void DebugController::Poll()
	{
		for (auto& key : m_PressedKeys)
		{
			switch (key)
			{
#if ORI_X_PLUS_BTN
			case ORI_X_PLUS_BTN: m_Orientation.x += ORI_SPEED; break;
#endif
#if ORI_X_PLUS_BTN
			case ORI_X_PLUS_BTN: m_Orientation.x -= ORI_SPEED; break;
#endif
#if ORI_Y_MIN_BTN
			case ORI_Y_MIN_BTN:    m_Orientation.y += ORI_SPEED; break;
#endif
#if ORI_Y_PLUS_BTN
			case ORI_Y_PLUS_BTN:   m_Orientation.y -= ORI_SPEED; break;
#endif
#if ORI_Z_MIN_BTN
			case ORI_Z_MIN_BTN:  m_Orientation.z += ORI_SPEED; break;
#endif
#if ORI_Z_PLUS_BTN
			case ORI_Z_PLUS_BTN: m_Orientation.z -= ORI_SPEED; break;
#endif
#if ACC_X_PLUS_BTN
			case ACC_X_PLUS_BTN: m_NewAcceleration.x += ACC_SPEED; break;
#endif
#if ACC_X_MIN_BTN
			case ACC_X_MIN_BTN:  m_NewAcceleration.x -= ACC_SPEED; break;
#endif
#if ACC_Y_PLUS_BTN
			case ACC_Y_PLUS_BTN: m_NewAcceleration.y += ACC_SPEED; break;
#endif
#if ACC_Y_MIN_BTN
			case ACC_Y_MIN_BTN:  m_NewAcceleration.y -= ACC_SPEED; break;
#endif
#if ACC_Z_PLUS_BTN
			case ACC_Z_PLUS_BTN: m_NewAcceleration.z += ACC_SPEED; break;
#endif
#if ACC_Z_MIN_BTN
			case ACC_Z_MIN_BTN:  m_NewAcceleration.z -= ACC_SPEED; break;
#endif
			}
		}

		CalculateAccelerationDifference();
	}

	void DebugController::ResetAcceleration()
	{
		m_OldAcceleration = m_Acceleration;
		CalculateAccelerationDifference();
	}

	void DebugController::KeyPressedEvent(char key)
	{
		// Add Key if it is not in the Key vector
		if (std::find(m_PressedKeys.begin(), m_PressedKeys.end(), key) == m_PressedKeys.end())
		{
			m_PressedKeys.push_back(key);
		}
	}

	void DebugController::KeyReleasedEvent(char key)
	{
		// Erase Released key from Key vector
		m_PressedKeys.erase(std::remove(m_PressedKeys.begin(), m_PressedKeys.end(), key), m_PressedKeys.end());
	}

	void DebugController::CalculateAccelerationDifference()
	{
		m_Acceleration = m_NewAcceleration - m_OldAcceleration;
		m_OldAcceleration = m_NewAcceleration;
	}

	void DebugController::MouseMovedEvent(int x, int y)
	{
		m_NewAcceleration = { x * 0.25f, y * 0.25f, 0};
	}

	bool DebugController::IsKeyPressed(int key)
	{
		return std::find(m_PressedKeys.begin(), m_PressedKeys.end(), key) != m_PressedKeys.end();
	}
}