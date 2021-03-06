#include "oakpch.h"
#include "Oak/LayerStack.h"


namespace Oak {
    LayerStack::LayerStack() {
        m_LayerInsert = m_Layers.begin();
    }

    LayerStack::~LayerStack() {
        for (Layer* layer : m_Layers) {
            delete layer;
        }
    }

    // Layers are pusht to the front half of the List
    void LayerStack::PushLayer(Layer* layer){
        m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
    }

    // Overlays are pushed to the backhalf of the list
    void LayerStack::PushOverlay(Layer* overlay){
        m_Layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer* layer){
        auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
        if (it != m_Layers.end()) {
            m_Layers.erase(it);
            m_LayerInsert--;
        }

    }

    void LayerStack::PopOverlay(Layer* overlay){
        auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
        if (it != m_Layers.end()) {
            m_Layers.erase(it);
        }
    }

}