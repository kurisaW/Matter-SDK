## 1.Pimpl（Pointer to Implementation）

> 检索来源：[微软：Pimpl For Compile-Time Encapsulation (Modern C++)](https://learn.microsoft.com/en-us/cpp/cpp/pimpl-for-compile-time-encapsulation-modern-cpp?view=msvc-170)

### 概念

*pimpl idiom* 是一种新式 C++ 技术，用于隐藏实现、最小化耦合和分离接口。

Pimpl 意思为“具体实现的指针”（Pointer to Implementation），它通过一个私有的成员指针，将指针所指向的类的内部实现数据进行隐藏。是一种降低耦合性和分离接口实现的一个现代 C++ 技术，并有着“编译防火墙(compilation firewall)”的名头。

### 为什么使用Pimpl

下面是 pimpl idiom 如何改善软件开发生命周期：

- 编译依赖项的最小化。
- 接口和实现的分离。
- 可移植性。

## 2.CRTP（Curiously Recurring Template Pattern）

### 概念

CRTP（Curiously Recurring Template Pattern）是一种C++设计模式，它允许在基类模板中通过派生类的类型参数来实现一些特定的行为。CRTP的核心思想是，让派生类模板化其父类，从而实现对父类的自定义扩展。

### CRTP的优势

CRTP的主要优势在于：

- **编译时多态性**：与运行时多态性（虚函数）不同，CRTP在编译时解析函数调用，因此具有更高的性能。
- **代码重用**：基类模板中的通用实现可以在所有派生类中共享，从而减少了代码重复。
- **静态类型检查**：编译器可以检查是否存在派生类中所定义的函数，从而减少了错误。

### 项目中的使用实例

```cpp
template <class ImplClass>
class GenericThreadStackManagerImpl_RTThread
{
    //...
    
private:
    // Private members for use by this class only.
    inline ImplClass * Impl() { return static_cast<ImplClass *>(this); }
    
    //...
};
```

> 这是一个类的私有成员函数 `Impl()` 的定义。这个函数返回一个指向 `ImplClass` 类型的指针，该指针是通过将 `this` 指针进行类型转换得到的。通常情况下，这种技巧用于实现一种叫做 "Curiously Recurring Template Pattern (CRTP)" 的设计模式。CRTP 允许子类（或者模板参数类型）访问父类（或者模板定义者）的成员函数和数据成员，以实现一种更加灵活的继承和代码复用方式。

## 3.C++中的静态多态和动态多态

C++支持多种形式的多态，从表现的形式来看，有虚函数、模板、重载等，从绑定时间来看，可以分成静态多态和动态多态，也称为编译期多态和运行期多态。

### 什么是动态多态?

动态多态的设计思想：对于相关的对象类型，确定它们之间的一个共同功能集，然后在基类中，把这些共同的功能声明为多个公共的虚函数接口。各个子类重写这些虚函数，以完成具体的功能。客户端的代码（操作函数）通过指向基类的引用或指针来操作这些对象，对虚函数的调用会自动绑定到实际提供的子类对象上去。

```cpp
namespace DynamicPoly
{
    class Geometry
    {
    public:
        virtual void Draw()const = 0;
    };

    class Line : public Geometry
    {
    public:
        virtual void Draw()const{    std::cout << "Line Draw()\n";    }
    };

    class Circle : public Geometry
    {
    public:
        virtual void Draw()const{    std::cout << "Circle Draw()\n";    }
    };

    class Rectangle : public Geometry
    {
    public:
        virtual void Draw()const{    std::cout << "Rectangle Draw()\n";    }
    };

    void DrawGeometry(const Geometry *geo)
    {
        geo->Draw();
    }

    //动态多态最吸引人之处在于处理异质对象集合的能力
    void DrawGeometry(std::vector<DynamicPoly::Geometry*> vecGeo)
    {
        const size_t size = vecGeo.size();
        for(size_t i = 0; i < size; ++i)
            vecGeo[i]->Draw();
    }
}

void test_dynamic_polymorphism()
{
    DynamicPoly::Line line;
    DynamicPoly::Circle circle;
    DynamicPoly::Rectangle rect;
    DynamicPoly::DrawGeometry(&circle);

    std::vector<DynamicPoly::Geometry*> vec;
    vec.push_back(&line);
    vec.push_back(&circle);
    vec.push_back(&rect);
    DynamicPoly::DrawGeometry(vec);
}
```

动态多态本质上就是面向对象设计中的继承、多态的概念。动态多态中的接口是显式接口（虚函数），比如：

```cpp
void DoSomething(Widget& w)
{
    if( w.size() > 0 && w != someNastyWidget)
    {
        Widget temp(w);
        temp.normalize();
        temp.swap(w);
    }
}
```

对于上面的代码，这要求：

* 由于w的类型被声明为Widget，所以w必须支持Widget接口，且通常可以在源码中找出这些接口（比如Widget.h），因此这些接口也就是显示接口；
* Widget可能只是一个基类，他有子类，也就是说Widget的接口有可能是虚函数（比如上面的normalize），此时对接口的调用就表现出了运行时多态；

### 什么是静态多态？

静态多态的设计思想：对于相关的对象类型，直接实现它们各自的定义，不需要共有基类，甚至可以没有任何关系。只需要各个具体类的实现中要求相同的接口声明，这里的接口称之为隐式接口。客户端把操作这些对象的函数定义为模板，当需要操作什么类型的对象时，直接对模板指定该类型实参即可（或通过实参演绎获得）。

相对于面向对象编程中，以显式接口和运行期多态（虚函数）实现动态多态，在模板编程及泛型编程中，是以隐式接口和编译器多态来实现静态多态。

```cpp
namespace StaticPoly
{
    class Line
    {
    public:
        void Draw()const{    std::cout << "Line Draw()\n";    }
    };

    class Circle
    {
    public:
        void Draw(const char* name=NULL)const{    std::cout << "Circle Draw()\n";    }
    };

    class Rectangle
    {
    public:
        void Draw(int i = 0)const{    std::cout << "Rectangle Draw()\n";    }
    };

    template<typename Geometry>
    void DrawGeometry(const Geometry& geo)
    {
        geo.Draw();
    }

    template<typename Geometry>
    void DrawGeometry(std::vector<Geometry> vecGeo)
    {
        const size_t size = vecGeo.size();
        for(size_t i = 0; i < size; ++i)
            vecGeo[i].Draw();
    }
}

void test_static_polymorphism()
{
    StaticPoly::Line line;
    StaticPoly::Circle circle;
    StaticPoly::Rectangle rect;
    StaticPoly::DrawGeometry(circle);

    std::vector<StaticPoly::Line> vecLines;
    StaticPoly::Line line2;
    StaticPoly::Line line3;
    vecLines.push_back(line);
    vecLines.push_back(line2);
    vecLines.push_back(line3);
    //vecLines.push_back(&circle); //编译错误，已不再能够处理异质对象
    //vecLines.push_back(&rect);    //编译错误，已不再能够处理异质对象
    StaticPoly::DrawGeometry(vecLines);

    std::vector<StaticPoly::Circle> vecCircles;
    vecCircles.push_back(circle);
    StaticPoly::DrawGeometry(circle);
}
```

静态多态本质上就是模板的具现化。静态多态中的接口调用也叫做隐式接口，相对于显示接口由函数的签名式（也就是函数名称、参数类型、返回类型）构成，隐式接口通常由有效表达式组成， 比如：

```cpp
template<typename Widget,typename Other>
void DoSomething(Widget& w, const Other& someNasty)
{
    if( w.size() > 0 && w != someNasty) //someNastyT可能是是T类型的某一实例，也可能不是
    {
        Widget temp(w);
        temp.normalize();
        temp.swap(w);
    }
}
```

这看似要求：

* 类型T需要支持size、normalize、swap函数，copy构造函数，可以进行不等比较
* 类型T是在编译期模板进行具现化时才表现出调用不同的函数，此时对接口的调用就表现出了编译期时多态。

但是，

* size函数并不需要返回一个整型值以和10比较，甚至都不需要返回一个数值类型，唯一的约束是它返回一个类型为X的对象，且X对象和int类型（数值10的类型）可以调用一个operator >，这个operator>也不一定非要一个X类型的参数不可，它可以通过隐式转换能将X类型转为Y类型对象，而只需要Y类型可以和int类型比较即可(好绕口，请看，这也侧面印证了模板编程编译错误很难解决)。
* 同样类型T并不需要支持operator!=，而只需要T可以转为X类型对象，someNastyT可以转为Y类型对象，而X和Y可以进行不等比较即可。


### 动态多态和静态多态的比较

**不同点：**

* 本质不同，静态多态在编译期决定，由模板具现完成，而动态多态在运行期决定，由继承、虚函数实现；
* 动态多态中接口是显式的，以函数签名为中心，多态通过虚函数在运行期实现，静态多台中接口是隐式的，以有效表达式为中心，多态通过模板具现在编译期完成

**相同点：**

* 都能够实现多态性，静态多态/编译期多态、动态多态/运行期多态；
* 都能够使接口和实现相分离，一个是模板定义接口，类型参数定义实现，一个是基类虚函数定义接口，继承类负责实现；