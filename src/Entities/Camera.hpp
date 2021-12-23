#ifndef LINAL_ASSESSMENT_CAMERA_HPP
#define LINAL_ASSESSMENT_CAMERA_HPP

#include "Engine/Input.hpp"

#include "Common/ITransformable.hpp"
#include "Common/IUpdatable.hpp"

const double MovementSpeed = 0.5;

namespace linal::entities
{
    class Camera : public common::ITransformable, public common::IUpdatable
    {
        private:
            models::Vector _eye;
            models::Vector _lookAt;
            double _near;
            double _far;
            double _fov;

            models::Vector _originalEye;
            models::Vector _originalLookAt;

        public:
            Camera(const models::Vector& eye, const models::Vector& lookAt, double near = 0.1, double far = 100, double fov = 60) : _eye(eye),
                                                                                                                                    _lookAt(lookAt),
                                                                                                                                    _near(near),
                                                                                                                                    _far(far),
                                                                                                                                    _fov(fov),
                                                                                                                                    _originalEye(eye),
                                                                                                                                    _originalLookAt(lookAt)
            {
            }

            void Transform(const models::Matrix& matrix) override
            {
            }

            void OnUpdate() override
            {
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_8_AND_UP_ARROW))
                {
                    Move(Up(), -MovementSpeed);
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_2_AND_DOWN_ARROW))
                {
                    Move(Up(), MovementSpeed);
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_4_AND_LEFT_ARROW))
                {
                    Move(Right(), -MovementSpeed);
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_6_AND_RIGHT_ARROW))
                {
                    Move(Right(), MovementSpeed);
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_9_AND_PAGE_UP))
                {
                    Move(Direction(), -MovementSpeed);
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_3_AND_PAGE_DOWN))
                {
                    Move(Direction(), MovementSpeed);
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_5))
                {
                    _eye = _originalEye;
                    _lookAt = _originalLookAt;
                }
            }

            void Move(const models::Vector& direction, double multiplier)
            {
                _eye.x += direction.x * multiplier;
                _eye.y += direction.y * multiplier;
                _eye.z += direction.z * multiplier;

                _lookAt.x += direction.x * multiplier;
                _lookAt.y += direction.y * multiplier;
                _lookAt.z += direction.z * multiplier;
            }

            [[nodiscard]] models::Vector Direction() const
            {
                return (_eye - _lookAt).Unit();
            }

            [[nodiscard]] models::Vector Right() const
            {
                const models::Vector up{0, 1, 0};

                return up.CrossProduct(Direction()).Unit();
            }

            [[nodiscard]] models::Vector Up() const
            {
                return Direction().CrossProduct(Right()).Unit();
            }

            [[nodiscard]] models::Matrix Translation() const
            {
                return models::Matrix::Camera(_eye, Right(), Up(), Direction());
            }

            [[nodiscard]] models::Matrix Projection() const
            {
                return models::Matrix::Projection(_near, _far, _fov);
            }

            [[nodiscard]] models::Matrix CameraView() const
            {
                return Projection() * Translation();
            }
    };
}

#endif //LINAL_ASSESSMENT_CAMERA_HPP
