#include <Oak.h>

class ExampleLayer : public Oak::Layer {
public:
    ExampleLayer() : Layer("Example") {
    }

    void OnUpdate() override {
        OAK_INFO("ExampleLayer::Update");
    }

    void OnEvent(Oak::Event& event) override {
        OAK_TRACE("{0}", event);
    }
};

class Sandbox : public Oak::Application {
public:
    Sandbox() {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox() {

    }
};

Oak::Application* Oak::CreateApplication() {
    return new Sandbox();
}