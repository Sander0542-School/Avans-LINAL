#ifndef LINAL_ASSESSMENT_CAMERA_HPP
#define LINAL_ASSESSMENT_CAMERA_HPP

#include "Engine/Input.hpp"

#include "Common/ITransformable.hpp"
#include "Common/IUpdatable.hpp"

const double MovementSpeed = 1;

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

        public:
            Camera(const models::Vector& eye, const models::Vector& lookAt, double near = 0.1, double far = 100, double fov = 60) : _eye(eye),
                                                                                                                                    _lookAt(lookAt),
                                                                                                                                    _near(near),
                                                                                                                                    _far(far),
                                                                                                                                    _fov(fov),
                                                                                                                                    _originalEye(eye)
            {
            }

            void Transform(const models::Matrix& matrix) override
            {
            }

            void OnUpdate() override
            {
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_8_AND_UP_ARROW))
                {
                    _eye.y += MovementSpeed;
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_2_AND_DOWN_ARROW))
                {
                    _eye.y -= MovementSpeed;
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_4_AND_LEFT_ARROW))
                {
                    _eye.x -= MovementSpeed;
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_6_AND_RIGHT_ARROW))
                {
                    _eye.x += MovementSpeed;
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_9_AND_PAGE_UP))
                {
                    _eye.z += MovementSpeed;
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_3_AND_PAGE_DOWN))
                {
                    _eye.z -= MovementSpeed;
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::KEYPAD_5))
                {
                    _eye = _originalEye;
                }
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
