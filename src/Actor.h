#include <vector>

class Actor {
    public:
    virtual void render() = 0;
    virtual void update() = 0;
    static std::vector<Actor*>& actors();
    private:
        static std::vector<Actor*>* actors_;
};
