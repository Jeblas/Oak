#pragma once

#include "Oak/Core.h"
#include "Oak/Events/Event.h"

namespace Oak {

    // Intended use is to created a subclass that implements Layer
    class OAK_API Layer {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}

        // Layers names used only for debugging purposes
        inline const std::string& GetName() const { return m_DebugName; }

    protected:
        std::string m_DebugName;
    };

}