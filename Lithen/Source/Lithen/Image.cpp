#include "Image.h"
#include "Application.h"

#include <glad/glad.h>

#include <imgui.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace Lithen
{

	namespace Utils {

		static uint32_t BytesPerPixel(ImageFormat format)
		{
			switch (format)
			{
			case ImageFormat::RGBA:    return 4;
			case ImageFormat::RGBA32F: return 16;
			}
			return 0;
		}

		static GLenum LithenFormatToGLInternalFormat(ImageFormat format)
		{
			switch (format)
			{
			case ImageFormat::RGBA:    return GL_RGBA8;
			case ImageFormat::RGBA32F: return GL_RGBA32F;
			}
			return 0;
		}

		static GLenum LithenFormatToGLDataFormat(ImageFormat format)
		{
			switch (format)
			{
			case ImageFormat::RGBA:    return GL_RGBA;
			case ImageFormat::RGBA32F: return GL_RGBA;
			}
			return 0;
		}

		static GLenum LithenFormatToGLDataType(ImageFormat format)
		{
			switch (format)
			{
			case ImageFormat::RGBA:    return GL_UNSIGNED_BYTE;
			case ImageFormat::RGBA32F: return GL_FLOAT;
			}
			return 0;
		}
	}

	Image::Image(std::string_view path)
		: m_Filepath(path)
	{
		int width, height, channels;
		uint8_t* data = nullptr;

		if (stbi_is_hdr(m_Filepath.c_str()))
		{
			data = (uint8_t*)stbi_loadf(m_Filepath.c_str(), &width, &height, &channels, 4);
			m_Format = ImageFormat::RGBA32F;
		}
		else
		{
			data = stbi_load(m_Filepath.c_str(), &width, &height, &channels, 4);
			m_Format = ImageFormat::RGBA;
		}

		m_Width = width;
		m_Height = height;

		AllocateMemory(m_Width * m_Height * Utils::BytesPerPixel(m_Format));
		SetData(data);
		stbi_image_free(data);
	}

	Image::Image(uint32_t width, uint32_t height, ImageFormat format, const void* data)
		: m_Width(width), m_Height(height), m_Format(format)
	{
		AllocateMemory(m_Width * m_Height * Utils::BytesPerPixel(m_Format));
		if (data)
			SetData(data);
	}

	Image::~Image()
	{
		Release();
	}

	void Image::AllocateMemory(uint64_t size)
	{
		glGenTextures(1, &m_RendererID);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		GLenum internalFormat = Utils::LithenFormatToGLInternalFormat(m_Format);
		GLenum dataFormat = Utils::LithenFormatToGLDataFormat(m_Format);
		GLenum dataType = Utils::LithenFormatToGLDataType(m_Format);

		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, m_Width, m_Height, 0, dataFormat, dataType, nullptr);
	}

	void Image::Release()
	{
		if (m_RendererID)
		{
			glDeleteTextures(1, &m_RendererID);
			m_RendererID = 0;
		}
	}

	void Image::SetData(const void* data)
	{
		GLenum dataFormat = Utils::LithenFormatToGLDataFormat(m_Format);
		GLenum dataType = Utils::LithenFormatToGLDataType(m_Format);

		glBindTexture(GL_TEXTURE_2D, m_RendererID);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_Width, m_Height, dataFormat, dataType, data);
	}

	void Image::Resize(uint32_t width, uint32_t height)
	{
		if (m_RendererID && m_Width == width && m_Height == height)
			return;

		m_Width = width;
		m_Height = height;

		Release();
		AllocateMemory(m_Width * m_Height * Utils::BytesPerPixel(m_Format));
	}
}
