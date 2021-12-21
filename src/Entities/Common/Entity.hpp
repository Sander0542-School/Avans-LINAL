#ifndef LINAL_OPDRACHTEN_IOBJECT_HPP
#define LINAL_OPDRACHTEN_IOBJECT_HPP

#include "IDrawable.hpp"
#include "IUpdatable.hpp"
#include "ITransformable.hpp"

#include "Models/Models.hpp"

#include <map>
#include <vector>

namespace linal::entities::common
{
    class Entity : public IDrawable, public ITransformable, public IUpdatable
    {
        protected:
            models::Matrix _rollLeftMatrix = models::Matrix::Roll(2.5);
            models::Matrix _rollRightMatrix = models::Matrix::Roll(-2.5);
            models::Matrix _yawLeftMatrix = models::Matrix::Yaw(2.5);
            models::Matrix _yawRightMatrix = models::Matrix::Yaw(-2.5);
            models::Matrix _pitchLeftMatrix = models::Matrix::Pitch(2.5);
            models::Matrix _pitchRightMatrix = models::Matrix::Pitch(-2.5);
            models::Matrix _scaleUpMatrix = models::Matrix::Scaling(1.05, 1.05, 1.05);
            models::Matrix _scaleDownMatrix = models::Matrix::Scaling(0.95, 0.95, 0.95);

            models::Matrix topMatrix = models::Matrix::Translation(0, 1, 0);
            models::Matrix rightMatrix = models::Matrix::Translation(1, 0, 0);
            models::Matrix bottomMatrix = models::Matrix::Translation(0, -1, 0);
            models::Matrix leftMatrix = models::Matrix::Translation(-1, 0, 0);

            models::Point _center{0, 0, 0};
            std::vector<models::Point> _points{};
            std::vector<std::pair<size_t, size_t>> _lines{};

        public:
            void Transform(const models::Matrix& matrix) override
            {
                _center = matrix * _center;
                for (auto& point: _points)
                {
                    point = matrix * point;
                }
            }

            void Draw(engine::Window& window, std::shared_ptr<entities::Camera> camera, const engine::Color& color) override
            {
                auto windowCenter = window.Size() * 0.5;

                std::vector<models::Point> points;

                for (const auto& point: _points)
                {
                    auto cameraPoint = camera->CameraView() * point;

                    auto x = windowCenter.x + (cameraPoint.x / cameraPoint.w) * windowCenter.x;
                    auto y = windowCenter.y + (cameraPoint.y / cameraPoint.w) * windowCenter.y;

                    points.emplace_back(x, y, -cameraPoint.z);
                }

                window.SetDrawColor(color);
                for (const auto&[from, to]: _lines)
                {
                    const auto& beginPoint = points[from];
                    const auto& endPoint = points[to];

                    if (beginPoint.w >= 0 && endPoint.w >= 0)
                    {
                        window.RenderLine(beginPoint.x, beginPoint.y, endPoint.x, endPoint.y);
                    }
                }
            }

            [[nodiscard]] models::Point Center() const
            {
                return _center;
            }

            void OnUpdate() override
            {
                // ROTATION: ROLL
                if (engine::Input::GetKey(engine::Input::KeyCode::Q))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _rollLeftMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::E))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _rollRightMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }

                // ROTATION: YAW
                if (engine::Input::GetKey(engine::Input::KeyCode::A))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _yawLeftMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::D))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _yawRightMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }

                // ROTATION: PITCH
                if (engine::Input::GetKey(engine::Input::KeyCode::W))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _pitchLeftMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::S))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _pitchRightMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }

                // SCALING
                if (engine::Input::GetKey(engine::Input::KeyCode::R))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _scaleUpMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::F))
                {
                    auto center = this->Center();
                    this->Transform(models::Matrix::Translation(center.x, center.y, center.z) * _scaleDownMatrix * models::Matrix::Translation(-center.x, -center.y, -center.z));
                }

                // MOMEMENT
                if (engine::Input::GetKey(engine::Input::KeyCode::I))
                {
                    this->Transform(topMatrix);
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::J))
                {
                    this->Transform(leftMatrix);
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::K))
                {
                    this->Transform(bottomMatrix);
                }
                if (engine::Input::GetKey(engine::Input::KeyCode::L))
                {
                    this->Transform(rightMatrix);
                }
            }

    };
}

#endif //LINAL_OPDRACHTEN_IOBJECT_HPP
