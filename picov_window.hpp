#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace picov {

	class PicovWindow {

		public:
			PicovWindow(int w, int h, std::string name);
			~PicovWindow();

			PicovWindow(const PicovWindow&) = delete;
			PicovWindow& operator=(const PicovWindow&) = delete;

			bool shouldClose() { return glfwWindowShouldClose(window); }
			VkExtent2D getExtent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }

			void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

		private:
			void initWindow();

			const int width;
			const int height;
			 
			std::string windowName;
			GLFWwindow* window;

	};
}