#ifndef RTIN1WEEKEND_HITTABLE_LIST_H
#define RTIN1WEEKEND_HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr, std::make_shared;

class hittable_list: public hittable {
private:
    std::vector<shared_ptr<hittable>> objects;
public:
    hittable_list()
        : objects({}) {}

    hittable_list(shared_ptr<hittable> object)
        : objects({object}) {
    }

    void clear() {
        objects.clear();
    }

    std::vector<shared_ptr<hittable>>::iterator
    add(shared_ptr<hittable> object) {
        objects.push_back(object);
        return objects.end() - 1;
    }

    virtual bool hit(
            const ray&  r,
            double      t_min,
            double      t_max,
            hit_record& rec
            ) const override;
};

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto& object : objects) {
        if (object->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

#endif //RTIN1WEEKEND_HITTABLE_LIST_H
