#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) 
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Initializing Log");
	HZ_INFO("Hello");


	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
	
}

#endif // HZ_PLATFORM_WINDOWS
