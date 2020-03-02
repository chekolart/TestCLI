#define WRAPPER
#include "Wrapper.h"
#pragma managed
#include <gcroot.h>
#include <iostream>

namespace Wrapper {
    public class WrapperImpl : public Wrapper
    {
    public:
        WrapperImpl():Wrapper()
        {
            managedObject = gcnew ManagedLibrary::ManagedClass();
        }

        void SayHello() override
        {
            managedObject->SayHello();
        }

    private:
        gcroot<ManagedLibrary::ManagedClass^> managedObject;
    };

    std::unique_ptr<Wrapper> CreateWrapper()
    {
        return std::make_unique<WrapperImpl>();
    }
}

//int main()
//{
//    std::unique_ptr<Wrapper::Wrapper> p_wrapper = Wrapper::CreateWrapper();
//    p_wrapper->SayHello();
//    std::cout << "Press any key." << std::endl;
//    getchar();
//
//}