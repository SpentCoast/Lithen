#pragma once

#include <string>

namespace Lithen {

	enum class ImageFormat
	{
		None = 0,
		RGBA,
		RGBA32F
	};

	class Image
	{
	public:
		Image(std::string_view path);
		Image(uint32_t width, uint32_t height, ImageFormat format, const void* data = nullptr);
		~Image();

		void SetData(const void* data);

		uint32_t GetRendererID() const { return m_RendererID; }

		void Resize(uint32_t width, uint32_t height);

		uint32_t GetWidth() const { return m_Width; }
		uint32_t GetHeight() const { return m_Height; }

	private:
		void AllocateMemory(uint64_t size);
		void Release();
	private:
		uint32_t m_Width = 0, m_Height = 0;

		uint32_t m_RendererID = 0;

		ImageFormat m_Format = ImageFormat::None;

		std::string m_Filepath;
	};

}
