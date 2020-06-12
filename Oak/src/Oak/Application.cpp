#include "oakpch.h"
#include "Application.h"

#include "Oak/Events/ApplicationEvent.h"
#include "Oak/Log.h"


namespace Oak {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {

			OAK_TRACE(e);

		}
		if (e.IsInCategory(EventCategoryInput)) {
			OAK_TRACE(e);
		}

		while (true);
	}

}
