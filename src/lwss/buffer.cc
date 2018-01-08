#include <lwss/buffer.hh>

namespace lwss {
    Buffer::Buffer(const void* data, std::size_t bytes, Type type, Usage usage)
                  : type { type } {
        glGenBuffers(1, &handle);
        glBindBuffer(static_cast<GLenum>(type), handle);
        glBufferData(static_cast<GLenum>(type), bytes, data, static_cast<GLenum>(usage));
    }

    Buffer::~Buffer() noexcept {
        glDeleteBuffers(1, &handle);
    }

    void Buffer::bind() const {
        glBindBuffer(static_cast<GLenum>(type), handle);
    }
}