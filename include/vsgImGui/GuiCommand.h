#pragma once

#include <vsg/viewer/Window.h>
#include <functional>

#include <vsgImGui/Export.h>
#include <vsgImGui/imgui.h>

namespace vsgImGui
{

    class VSGIMGUI_DECLSPEC GuiCommand : public vsg::Inherit<vsg::Command, GuiCommand>
    {
        public:
            GuiCommand( const vsg::ref_ptr<vsg::Window> &window );

            using RenderCallback = std::function<void()>;
            void setRenderCallback(const RenderCallback &callback);

            void render() const;

            void record(vsg::CommandBuffer& commandBuffer) const override;

        private:
            virtual ~GuiCommand();

            VkInstance _instance;
            VkDevice _device;
            uint32_t _queueFamily;
            VkQueue _queue;
            VkDescriptorPool _descriptorPool;
            VkCommandPool _commandPool;
            RenderCallback _renderCallback;

            void _init( const vsg::ref_ptr<vsg::Window> &window );
            void _uploadFonts( const vsg::ref_ptr<vsg::Window> &window );
    };

}

EVSG_type_name(vsgImGui::GuiCommand);