#include <iostream>
#include <string>

class Product {
public:
    void setName(const std::string& name) {
        name_ = name;
    }

    void setPrice(double price) {
        price_ = price;
    }

    void setIngredients(const std::string& ingredients) {
        ingredients_ = ingredients;
    }

    void displayInfo() const {
        std::cout << "Product: " << name_ << "\n";
        std::cout << "Price: " << price_ << "\n";
        std::cout << "Ingredients: " << ingredients_ << "\n\n";
    }

private:
    std::string name_;
    double price_;
    std::string ingredients_;
};

class ProductBuilder {
public:
    virtual void buildName() = 0;
    virtual void buildPrice() = 0;
    virtual void buildIngredients() = 0;
    virtual Product getProduct() = 0;
};

class CoffeeBuilder : public ProductBuilder {
public:
    CoffeeBuilder() {
        product_.setName("Coffee");
    }

    void buildName() override {}

    void buildPrice() override {
        product_.setPrice(2.5);
    }

    void buildIngredients() override {
        product_.setIngredients("Coffee beans, water, milk (optional), sugar (optional)");
    }

    Product getProduct() override {
        return product_;
    }

private:
    Product product_;
};

class Director {
public:
    void setBuilder(ProductBuilder* builder) {
        builder_ = builder;
    }

    Product constructProduct() {
        builder_->buildName();
        builder_->buildPrice();
        builder_->buildIngredients();
        return builder_->getProduct();
    }

private:
    ProductBuilder* builder_;
};

int main() {
    Director director;
    CoffeeBuilder coffeeBuilder;
    
    director.setBuilder(&coffeeBuilder);
    Product coffee = director.constructProduct();
    
    coffee.displayInfo();

    return 0;
}
