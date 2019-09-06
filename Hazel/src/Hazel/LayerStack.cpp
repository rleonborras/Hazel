#include "hzpch.h"
#include "LayerStack.h"


namespace Hazel {

	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();

	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer * Layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, Layer);

	}

	void LayerStack::PushOverlay(Layer * Layer)
	{
		m_Layers.emplace_back(Layer);
	}

	void LayerStack::PopLayer(Layer * Layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), Layer);
		if (it != m_Layers.end()) {
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer * Layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), Layer);
		if (it != m_Layers.end()) {
			m_Layers.erase(it);
		}

	}

}