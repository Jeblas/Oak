#pragma once

#ifdef OAK_PLATFORM_WINDOWS

extern Oak::Application* Oak::CreateApplication();

int main(int argc, char** argv) {

	Oak::Log::Init();
	OAK_CORE_WARN("Initialized Log!");

	int a = 52;
	OAK_INFO("Test! Var= {0}", a);

	auto app = Oak::CreateApplication();
	app->Run();
	delete	app;
}

#else 
	
#endif