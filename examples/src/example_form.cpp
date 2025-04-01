#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <GL/gl.h>
#include <cpp-forms/form.hpp>

#include "imgui-forms/bindings.hpp"
#include "imgui-forms/field_traits.hpp"
#include "imgui-forms/field_traits_macros.hpp"
#include "imgui-forms/input_text_utils.hpp"
#include "example_form_traits.hpp"

int main()
{
    if (!glfwInit())
        return 1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow *window = glfwCreateWindow(800, 600, "Dear ImGui Example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    ImGui::CreateContext();

    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    ExampleTraitsModel model = {"John", "john@example.com"};

    cpp_forms::Form<ExampleTraitsModel> form(model);

    imgui_forms::Bindings<ExampleTraitsModel> bindings(form);
    bindings.setBufferCapacity("name", 12);
    bindings.setBufferCapacity("email", 12);

    ImGui::GetIO().FontGlobalScale = 2.0f;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        if (ImGui::Begin("Hello, world!"))
        {
            ImGui::Text("Hello, world!");
            ImGuiInputTextFlags flags = ImGuiInputTextFlags_CallbackResize;
            // auto nameBinding = bindings["name"];

            if (ImGui::InputText("Input Text",
                                 bindings["name"].data(),
                                 bindings["name"].capacity(),
                                 flags,
                                 imgui_forms::InputTextCallback,
                                 &bindings["name"].buffer))
            {
                std::cout << "name in inputtext: " << bindings["name"].data() << std::endl;
            }
            if (ImGui::Button("Submit"))
            {
                bindings.commitAll();
                form.commit(); // Write buffer value to the form model
                std::cout << "name in submit: " << model.name << std::endl;
            }
            if (ImGui::Button("Clear"))
            {
                bindings.clear();
            }
        }
        ImGui::End();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}