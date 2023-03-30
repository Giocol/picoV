#pragma once

#include "picov_device.hpp"

#include <string>
#include <vector>

namespace picov {

	struct PipelineConfigInfo {
		PipelineConfigInfo(const PipelineConfigInfo&) = delete;
		PipelineConfigInfo& operator=(const PipelineConfigInfo&) = delete;
		VkViewport viewport;
		VkRect2D scissor;
		VkPipelineViewportStateCreateInfo viewportInfo;
		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;
		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		VkPipelineLayout pipelineLayout = nullptr;
		VkRenderPass renderPass = nullptr;
		uint32_t subpass = 0;
	};

	class PicovPipeline {
		public:
			PicovPipeline(
				PicovDevice& device,
				const std::string& vertFilepath,
				const std::string& fragFilepath,
				const PipelineConfigInfo& configInfo);
			~PicovPipeline();

			// delete copy constructors, to avoid duplicating pointers to VK objects
			PicovPipeline(const PicovPipeline&) = delete;
			void operator = (const PicovPipeline&) = delete;

			void bind(VkCommandBuffer commandBuffer);
			static void defaultPipelineConfigInfo(
				PipelineConfigInfo& configInfo, uint32_t width, uint32_t height);

		private:
			static std::vector<char> readFile(const std::string& filepath);

			void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& config);
			
			void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

			//memory unsafe, but it shouldn't be a problem because a pipeline needs a device to exist
			PicovDevice& picovDevice;
			VkPipeline graphicsPipeline;
			VkShaderModule vertShaderModule;
			VkShaderModule fragShaderModule;
	};
}