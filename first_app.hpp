#pragma once

#include "picov_window.hpp"
#include "picov_pipeline.hpp"
#include "picov_device.hpp"
#include "picov_swap_chain.hpp"

#include <memory>
#include <vector>

namespace picov {
	class FirstApp {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		FirstApp();
		~FirstApp();

		FirstApp(const FirstApp&) = delete;
		FirstApp& operator=(const FirstApp&) = delete;

		void run();
	private:
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();

		PicovWindow picovWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
		PicovDevice picovDevice{ picovWindow };
		PicovSwapChain picovSwapChain{ picovDevice, picovWindow.getExtent() };
		std::unique_ptr<PicovPipeline> picovPipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
	};
}