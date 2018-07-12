
#pragma once

#include <memory>

namespace pride
{
    template<typename Derived>
    class shareable : public std::enable_shared_from_this<Derived>
    {
        using std::enable_shared_from_this<Derived>::shared_from_this;

    public:
        using ptr = std::shared_ptr<Derived>;
        using const_ptr = std::shared_ptr<const Derived>;
        using weak_ptr = std::weak_ptr<Derived>;
        using const_weak_ptr = std::weak_ptr<const Derived>;

        ptr get() { return share_from_this(); }
        const_ptr get() const { return shared_from_this(); }

        weak_ptr get_weak() { return weak_from_this(); }
        const_weak_ptr get_weak() const { return weak_from_this(); }

        template<typename... Args>
        static ptr make_new(Args&&... args)
        {
            return std::make_shared<Derived>(std::forward<Args>(args)...);
        }

    protected:
        using allocator = std::_Ref_count_obj<Derived>;
    };
}