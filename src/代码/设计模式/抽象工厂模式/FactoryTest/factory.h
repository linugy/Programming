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

//-----------------------------------------

// 其他产品基类
class ProductOther
{
public:
    virtual void showOther() = 0;
};

// 其他产品A
class ProductOtherA : public ProductOther
{
public:
    void showOther();
};

// 其他产品B
class ProductOtherB : public ProductOther
{
public:
    void showOther();
};

//----------------------------------------

// 工厂
class Factory
{
public:
    virtual Product *createObj() = 0;
    virtual ProductOther *createObjOther() = 0;
};

// 工厂A
class FactoryA : public Factory
{
public:
    Product *createObj();
    ProductOther *createObjOther();
};

// 工厂B
class FactoryB : public Factory
{
public:
    Product *createObj();
    ProductOther *createObjOther();
};

#endif // FACTORY_H
