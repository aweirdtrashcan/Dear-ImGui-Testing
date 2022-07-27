#include "UseImGui.h"

void UseImGui::Init(GLFWwindow *window, const char *glsl_version)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
	ImGui::StyleColorsDark();

}

void UseImGui::NewFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void UseImGui::Update()
{
	static float f = 0.0f;

	ImGui::Begin("My Logo");

	ImGui::Text("Matheus viado");
	ImGui::SliderFloat("float", &f, 100.0f, 1000.0f);
	ImGui::Text("%1.f", f);

	ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);

	ImGui::End();
}

void UseImGui::Render()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UseImGui::Shutdown()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
