#pragma once
#include "Hazel/Layer.h"


namespace Hazel {

	class ImGuiLayer : public Layer 
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate();
		void OnAttach();
		void OnDetach();

		void onEvent(Event& event);

	private:

	};



}