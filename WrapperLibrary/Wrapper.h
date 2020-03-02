#pragma once
#pragma unmanaged
#include <memory>

#ifdef WRAPPER
#define EXPORT extern __declspec(dllexport)
#else
#define EXPORT extern __declspec(dllimport)
#endif

namespace Wrapper
{
    class Wrapper {
    public:
        Wrapper() = default;
        virtual void SayHello() = 0;
        virtual ~Wrapper() = default;
    private:
        Wrapper(const Wrapper&) = delete;
        Wrapper(Wrapper&&) = delete;
        Wrapper& operator=(const Wrapper&) = delete;
        Wrapper& operator=(Wrapper&&) = delete;
    };

    EXPORT std::unique_ptr<Wrapper> CreateWrapper();
}
