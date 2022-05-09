#ifndef FACTORY_H
#define FACTORY_H

// 产品基类
class Product
{
public:
    virtual void show() = 0;
};

// 产品A
class ProductA : public Product
{
public:
    void show();
};

// 产品B
class ProductB : public Product
{
public:
    void show();
};

// 工厂
class Factory
{
public:
    virtual Product *createObj() = 0;
};

// 工厂A
class FactoryA : public Factory
{
public:
    Product *createObj();
};

// 工厂B
class FactoryB : public Factory
{
public:
    Product *createObj();
};

#endif // FACTORY_H
