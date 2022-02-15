#ifndef LINAL_OPDRACHTEN_IOBJECT_HPP
#define LINAL_OPDRACHTEN_IOBJECT_HPP

#include "IDrawable.hpp"
#include "IUpdatable.hpp"
#include "ITransformable.hpp"

#include "Models/Models.hpp"
#include "Config.hpp"

#include <map>
#include <vector>

namespace linal::entities::common
{
    class Entity : public IDrawable, public ITransformable, public IUpdatable
    {
        protected:
            models::Matrix _scaleUpMatrix = models::Matrix::Scaling(1.05, 1.05, 1.05);
            models::Matrix _scaleDownMatrix = models::Matrix::Scaling(0.95, 0.95, 0.95);

            models::Matrix topMatrix = models::Matrix::Translation(0, 1, 0);
            models::Matrix rightMatrix = models::Matrix::Translation(1, 0, 0);
            models::Matrix bottomMatrix = models::Matrix::Translation(0, -1, 0);
            models::Matrix leftMatrix = models::Matrix::Translation(-1, 0, 0);

            models::Point _center{0, 0, 0};
            models::Point _rollPoint{0, 0, 5};
            models::Point _pitchPoint{5, 0, 0};
            models::Point _yawPoint{0, 5, 0};
            std::vector<models::Point> _points{};
            std::vector<std::pair<size_t, size_t>> _lines{};

        public:
            void Transform(const models::Matrix& matrix) override
            {
                _center = matrix * _center;
                _rollPoint = matrix * _rollPoint;
                _pitchPoint = matrix * _pitchPoint;
                _yawPoint = matrix * _yawPoint;
                for (auto& point: _points)
                {
                    point = matrix * point;
                }
            }

            void Draw(engine::Window& window, std::shared_ptr<entities::Camera> camera, const engine::Color& color) override
            {
                auto windowCenter = window.Size() * 0.5;
                auto cameraMatrix = camera->CameraView();

                std::vector<models::Point> points;

                for (const auto& point: _points)
                {
                    auto cameraPoint = cameraMatrix * point;

                    auto x = windowCenter.x + (cameraPoint.x / cameraPoint.w) * windowCenter.x;
                    auto y = windowCenter.y + (cameraPoint.y / cameraPoint.w) * windowCenter.y;

                    points.emplace_back(x, y, -cameraPoint.z, cameraPoint.z);
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

                    if (Config::Instance().DebugMode)
                    {
                        for (size_t i = 0; i < points.size(); i++)
                        {
                            window.RenderText(std::to_string(i), points[i], engine::Color::red());
                        }
                    }
                }

                models::Point cameraCenterPoint;
                {
                    auto centerCameraPoint = cameraMatrix * _center;

                    auto x = windowCenter.x + (centerCameraPoint.x / centerCameraPoint.w) * windowCenter.x;
                    auto y = windowCenter.y + (centerCameraPoint.y / centerCameraPoint.w) * windowCenter.y;

                    cameraCenterPoint = models::Point{x, y, -centerCameraPoint.z, centerCameraPoint.z};
                }
                {
                    auto rollCameraPoint = cameraMatrix * _rollPoint;

                    auto x = windowCenter.x + (rollCameraPoint.x / rollCameraPoint.w) * windowCenter.x;
                    auto y = windowCenter.y + (rollCameraPoint.y / rollCameraPoint.w) * windowCenter.y;

                    window.SetDrawColor(engine::Color::red());
                    window.RenderLine(cameraCenterPoint.x, cameraCenterPoint.y, x, y);
                }
                {
                    auto yawCameraPoint = cameraMatrix * _yawPoint;

                    auto x = windowCenter.x + (yawCameraPoint.x / yawCameraPoint.w) * windowCenter.x;
                    auto y = windowCenter.y + (yawCameraPoint.y / yawCameraPoint.w) * windowCenter.y;

                    window.SetDrawColor(engine::Color::blue());
                    window.RenderLine(cameraCenterPoint.x, cameraCenterPoint.y, x, y);
                }
                {
                    auto pitchCameraPoint = cameraMatrix * _pitchPoint;

                    auto x = windowCenter.x + (pitchCameraPoint.x / pitchCameraPoint.w) * windowCenter.x;
                    auto y = windowCenter.y + (pitchCameraPoint.y / pitchCameraPoint.w) * windowCenter.y;

                    window.SetDrawColor(engine::Color::green());
                    window.RenderLine(cameraCenterPoint.x, cameraCenterPoint.y, x, y);
                }
            }

            [[nodiscard]] models::Point Center() const
            {
                return _center;
            }

    };
}

#endif //LINAL_OPDRACHTEN_IOBJECT_HPP
