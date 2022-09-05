
#include "souffle/CompiledSouffle.h"
#include <mutex>
#include "souffle/Explain.h"

extern "C" {
}

namespace souffle {
using namespace ram;
struct t_btree_4__0_1_2_3__1__3__15 {
using t_tuple = Tuple<RamDomain, 4>;
struct updater_t_btree_4__0_1_2_3__1__3__15 {
void update(t_tuple& old_t, const t_tuple& new_t) {
old_t[2] = new_t[2];
old_t[3] = new_t[3];
}
};
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2,3>, std::allocator<t_tuple>, 256, typename souffle::detail::default_strategy<t_tuple>::type, index_utils::comparator<0,1>, updater_t_btree_4__0_1_2_3__1__3__15>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_4__0_1_2_3__1__3__15& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
context h;
return equalRange_1(t, h);
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
context h;
return equalRange_3(t, h);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t) const {
context h;
return equalRange_15(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 4 direct b-tree index [0,1,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_3__0_1_2__1__7 {
using t_tuple = Tuple<RamDomain, 3>;
struct updater_t_btree_3__0_1_2__1__7 {
void update(t_tuple& old_t, const t_tuple& new_t) {
old_t[1] = new_t[1];
old_t[2] = new_t[2];
}
};
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2>, std::allocator<t_tuple>, 256, typename souffle::detail::default_strategy<t_tuple>::type, index_utils::comparator<0>, updater_t_btree_3__0_1_2__1__7>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[3];
std::copy(ramDomain, ramDomain + 3, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2) {
RamDomain data[3] = {a0,a1,a2};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_3__0_1_2__1__7& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
context h;
return equalRange_1(t, h);
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_7(const t_tuple& t) const {
context h;
return equalRange_7(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 3 direct b-tree index [0,1,2]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15 {
using t_tuple = Tuple<RamDomain, 4>;
struct updater_t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15 {
void update(t_tuple& old_t, const t_tuple& new_t) {
old_t[2] = new_t[2];
old_t[3] = new_t[3];
}
};
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,3,2>, std::allocator<t_tuple>, 256, typename souffle::detail::default_strategy<t_tuple>::type, index_utils::comparator<0,1>, updater_t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>;
t_ind_0 ind_0;
using t_ind_1 = btree_set<t_tuple, index_utils::comparator<1,0,2,3>, std::allocator<t_tuple>, 256, typename souffle::detail::default_strategy<t_tuple>::type, index_utils::comparator<1,0>, updater_t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>;
t_ind_1 ind_1;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
t_ind_1::operation_hints hints_1;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
ind_1.insert(t, h.hints_1);
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15& other) {
ind_0.insertAll(other.ind_0);
ind_1.insertAll(other.ind_1);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_1(const t_tuple& t) const {
context h;
return equalRange_1(t, h);
}
range<t_ind_1::iterator> equalRange_2(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_1.lower_bound(low, h.hints_1), ind_1.upper_bound(high, h.hints_1));
}
range<t_ind_1::iterator> equalRange_2(const t_tuple& t) const {
context h;
return equalRange_2(t, h);
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
context h;
return equalRange_3(t, h);
}
range<t_ind_1::iterator> equalRange_15(const t_tuple& t, context& h) const {
auto pos = ind_1.find(t, h.hints_1);
auto fin = ind_1.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_1::iterator> equalRange_15(const t_tuple& t) const {
context h;
return equalRange_15(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
ind_1.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 4 direct b-tree index [0,1,3,2]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
const auto& stats_1 = ind_1.getHintStatistics();
o << prefix << "arity 4 direct b-tree index [1,0,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_1.inserts.getHits() << "/" << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_1.contains.getHits() << "/" << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_1.lower_bound.getHits() << "/" << stats_1.lower_bound.getMisses() << "/" << stats_1.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_1.upper_bound.getHits() << "/" << stats_1.upper_bound.getMisses() << "/" << stats_1.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_4__0_1_2_3__3__15 {
using t_tuple = Tuple<RamDomain, 4>;
struct updater_t_btree_4__0_1_2_3__3__15 {
void update(t_tuple& old_t, const t_tuple& new_t) {
old_t[2] = new_t[2];
old_t[3] = new_t[3];
}
};
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2,3>, std::allocator<t_tuple>, 256, typename souffle::detail::default_strategy<t_tuple>::type, index_utils::comparator<0,1>, updater_t_btree_4__0_1_2_3__3__15>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_4__0_1_2_3__3__15& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_3(const t_tuple& t) const {
context h;
return equalRange_3(t, h);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t) const {
context h;
return equalRange_15(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 4 direct b-tree index [0,1,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_4__1_0_2_3__2__15 {
using t_tuple = Tuple<RamDomain, 4>;
struct updater_t_btree_4__1_0_2_3__2__15 {
void update(t_tuple& old_t, const t_tuple& new_t) {
old_t[2] = new_t[2];
old_t[3] = new_t[3];
}
};
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<1,0,2,3>, std::allocator<t_tuple>, 256, typename souffle::detail::default_strategy<t_tuple>::type, index_utils::comparator<1,0>, updater_t_btree_4__1_0_2_3__2__15>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_4__1_0_2_3__2__15& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_2(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[0] = MIN_RAM_DOMAIN;
high[0] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_0.lower_bound(low, h.hints_0), ind_0.upper_bound(high, h.hints_0));
}
range<t_ind_0::iterator> equalRange_2(const t_tuple& t) const {
context h;
return equalRange_2(t, h);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t) const {
context h;
return equalRange_15(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 4 direct b-tree index [1,0,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_6__0_1_2_3_4_5__63 {
using t_tuple = Tuple<RamDomain, 6>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2,3,4,5>>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[6];
std::copy(ramDomain, ramDomain + 6, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4,RamDomain a5) {
RamDomain data[6] = {a0,a1,a2,a3,a4,a5};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_6__0_1_2_3_4_5__63& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_63(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_63(const t_tuple& t) const {
context h;
return equalRange_63(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 6 direct b-tree index [0,1,2,3,4,5]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};
struct t_btree_4__0_1_2_3__15 {
using t_tuple = Tuple<RamDomain, 4>;
struct updater_t_btree_4__0_1_2_3__15 {
void update(t_tuple& old_t, const t_tuple& new_t) {
old_t[2] = new_t[2];
old_t[3] = new_t[3];
}
};
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2,3>, std::allocator<t_tuple>, 256, typename souffle::detail::default_strategy<t_tuple>::type, index_utils::comparator<0,1>, updater_t_btree_4__0_1_2_3__15>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0;
};
context createContext() { return context(); }
bool insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0)) {
return true;
} else return false;
}
bool insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_4__0_1_2_3__15& other) {
ind_0.insertAll(other.ind_0);
}
bool contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0);
}
bool contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t size() const {
return ind_0.size();
}
iterator find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0);
}
iterator find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> equalRange_0(const t_tuple& t, context& h) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> equalRange_0(const t_tuple& t) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_15(const t_tuple& t) const {
context h;
return equalRange_15(t, h);
}
bool empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> partition() const {
return ind_0.getChunks(400);
}
void purge() {
ind_0.clear();
}
iterator begin() const {
return ind_0.begin();
}
iterator end() const {
return ind_0.end();
}
void printHintStatistics(std::ostream& o, const std::string prefix) const {
const auto& stats_0 = ind_0.getHintStatistics();
o << prefix << "arity 4 direct b-tree index [0,1,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
}
};

class Sf_program_small : public SouffleProgram {
private:
static inline bool regex_wrapper(const std::string& pattern, const std::string& text) {
   bool result = false; 
   try { result = std::regex_match(text, std::regex(pattern)); } catch(...) { 
     std::cerr << "warning: wrong pattern provided for match(\"" << pattern << "\",\"" << text << "\").\n";
}
   return result;
}
private:
static inline std::string substr_wrapper(const std::string& str, size_t idx, size_t len) {
   std::string result; 
   try { result = str.substr(idx,len); } catch(...) { 
     std::cerr << "warning: wrong index position provided by substr(\"";
     std::cerr << str << "\"," << (int32_t)idx << "," << (int32_t)len << ") functor.\n";
   } return result;
}
private:
static inline RamDomain wrapper_tonumber(const std::string& str) {
   RamDomain result=0; 
   try { result = stord(str); } catch(...) { 
     std::cerr << "error: wrong string provided by to_number(\"";
     std::cerr << str << "\") functor.\n";
     raise(SIGFPE);
   } return result;
}
public:
// -- initialize symbol table --
SymbolTable symTable
{
	R"_(v0,v1)_",
	R"_(Rule)_",
	R"_(precededBy,v0,v2)_",
	R"_(author,v1,v2)_",
	R"_(author(v0,v1) :- 
   Rule(194),
   precededBy(v0,v2),
   author(v1,v2).)_",
	R"_(precededBy,v2,v1)_",
	R"_(Iauthor,v2,v0)_",
	R"_(author(v0,v1) :- 
   Rule(172),
   precededBy(v2,v1),
   Iauthor(v2,v0).)_",
};// -- Table: Iauthor
std::unique_ptr<t_btree_4__0_1_2_3__1__3__15> rel_1_Iauthor = std::make_unique<t_btree_4__0_1_2_3__1__3__15>();
souffle::RelationWrapper<0,t_btree_4__0_1_2_3__1__3__15,Tuple<RamDomain,4>,4> wrapper_rel_1_Iauthor;
// -- Table: Rule
std::unique_ptr<t_btree_3__0_1_2__1__7> rel_2_Rule = std::make_unique<t_btree_3__0_1_2__1__7>();
souffle::RelationWrapper<1,t_btree_3__0_1_2__1__7,Tuple<RamDomain,3>,3> wrapper_rel_2_Rule;
// -- Table: precededBy
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_3_precededBy = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<2,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_3_precededBy;
// -- Table: author
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_4_author = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<3,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_4_author;
// -- Table: @delta_author
std::unique_ptr<t_btree_4__1_0_2_3__2__15> rel_5_delta_author = std::make_unique<t_btree_4__1_0_2_3__2__15>();
// -- Table: @new_author
std::unique_ptr<t_btree_4__1_0_2_3__2__15> rel_6_new_author = std::make_unique<t_btree_4__1_0_2_3__2__15>();
// -- Table: author.@info.1
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_7_author_info_1 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<4,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_7_author_info_1;
// -- Table: author.@info.2
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_8_author_info_2 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<5,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_8_author_info_2;
// -- Table: inv_0
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_9_inv_0 = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<6,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4> wrapper_rel_9_inv_0;
public:
Sf_program_small() : 
wrapper_rel_1_Iauthor(*rel_1_Iauthor,symTable,"Iauthor",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_2_Rule(*rel_2_Rule,symTable,"Rule",std::array<const char *,3>{{"i:number","i:number","i:number"}},std::array<const char *,3>{{"n","@rule_number","@level_number"}}),

wrapper_rel_3_precededBy(*rel_3_precededBy,symTable,"precededBy",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_4_author(*rel_4_author,symTable,"author",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_7_author_info_1(*rel_7_author_info_1,symTable,"author.@info.1",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_8_author_info_2(*rel_8_author_info_2,symTable,"author.@info.2",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_9_inv_0(*rel_9_inv_0,symTable,"inv_0",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}){
addRelation("Iauthor",&wrapper_rel_1_Iauthor,true,false);
addRelation("Rule",&wrapper_rel_2_Rule,true,false);
addRelation("precededBy",&wrapper_rel_3_precededBy,true,false);
addRelation("author",&wrapper_rel_4_author,false,true);
addRelation("author.@info.1",&wrapper_rel_7_author_info_1,false,false);
addRelation("author.@info.2",&wrapper_rel_8_author_info_2,false,false);
addRelation("inv_0",&wrapper_rel_9_inv_0,false,true);
}
~Sf_program_small() {
}
private:
void runFunction(std::string inputDirectory = ".", std::string outputDirectory = ".", size_t stratumIndex = (size_t) -1, bool performIO = false) {
SignalHandler::instance()->set();
std::atomic<size_t> iter(0);

#if defined(_OPENMP)
if (getNumThreads() > 0) {omp_set_num_threads(getNumThreads());}
#endif

// -- query evaluation --
/* BEGIN STRATUM 0 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Iauthor.facts"},{"name","Iauthor"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_Iauthor);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Rule.facts"},{"name","Rule"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->readAll(*rel_2_Rule);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./precededBy.facts"},{"name","precededBy"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_precededBy);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
SignalHandler::instance()->setMsg(R"_(author(v0,v1,2,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(172,_,@level_num_0),
   precededBy(v2,v1,_,@level_num_1),
   Iauthor(v2,v0,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/book/sol_author.dl [22:1-22:66])_");
if(!(rel_1_Iauthor->empty()) && !(rel_3_precededBy->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(172),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iauthor_op_ctxt,rel_1_Iauthor->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_precededBy_op_ctxt,rel_3_precededBy->createContext());
CREATE_OP_CONTEXT(rel_4_author_op_ctxt,rel_4_author->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_precededBy) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Iauthor->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iauthor_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(2)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_author->insert(tuple,READ_OP_CONTEXT(rel_4_author_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
rel_5_delta_author->insertAll(*rel_4_author);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(author(v0,v1,1,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(194,_,@level_num_0),
   precededBy(v0,v2,_,@level_num_1),
   author(v1,v2,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/book/sol_author.dl [21:1-21:65])_");
if(!(rel_5_delta_author->empty()) && !(rel_3_precededBy->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(194),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_precededBy_op_ctxt,rel_3_precededBy->createContext());
CREATE_OP_CONTEXT(rel_4_author_op_ctxt,rel_4_author->createContext());
CREATE_OP_CONTEXT(rel_5_delta_author_op_ctxt,rel_5_delta_author->createContext());
CREATE_OP_CONTEXT(rel_6_new_author_op_ctxt,rel_6_new_author->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_precededBy) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_5_delta_author->equalRange_2(key,READ_OP_CONTEXT(rel_5_delta_author_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_author->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_4_author_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(1)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_author->insert(tuple,READ_OP_CONTEXT(rel_6_new_author_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
if(rel_6_new_author->empty()) break;
rel_4_author->insertAll(*rel_6_new_author);
std::swap(rel_5_delta_author, rel_6_new_author);
rel_6_new_author->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_5_delta_author->purge();
if (!isHintsProfilingEnabled()) rel_6_new_author->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./author.csv"},{"name","author"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_author);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
SignalHandler::instance()->setMsg(R"_(author.@info.1(1,"v0,v1","Rule","precededBy,v0,v2","author,v1,v2","author(v0,v1) :- 
   Rule(194),
   precededBy(v0,v2),
   author(v1,v2).").
in file  [0:0-0:0])_");
rel_7_author_info_1->insert(RamDomain(1),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(3),RamDomain(4));
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
SignalHandler::instance()->setMsg(R"_(author.@info.2(2,"v0,v1","Rule","precededBy,v2,v1","Iauthor,v2,v0","author(v0,v1) :- 
   Rule(172),
   precededBy(v2,v1),
   Iauthor(v2,v0).").
in file  [0:0-0:0])_");
rel_8_author_info_2->insert(RamDomain(2),RamDomain(0),RamDomain(1),RamDomain(5),RamDomain(6),RamDomain(7));
}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./inv_0.csv"},{"name","inv_0"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_9_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 6 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_Iauthor:\n";
rel_1_Iauthor->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_Rule:\n";
rel_2_Rule->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_precededBy:\n";
rel_3_precededBy->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_author:\n";
rel_4_author->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_delta_author:\n";
rel_5_delta_author->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_new_author:\n";
rel_6_new_author->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_author_info_1:\n";
rel_7_author_info_1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_author_info_2:\n";
rel_8_author_info_2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_inv_0:\n";
rel_9_inv_0->printHintStatistics(std::cout,"  ");
std::cout << "\n";
}
SignalHandler::instance()->reset();
}
public:
void run(size_t stratumIndex = (size_t) -1) override { runFunction(".", ".", stratumIndex, false); }
public:
void runAll(std::string inputDirectory = ".", std::string outputDirectory = ".", size_t stratumIndex = (size_t) -1) override { runFunction(inputDirectory, outputDirectory, stratumIndex, true);
}
public:
void printAll(std::string outputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./author.csv"},{"name","author"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_author);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./inv_0.csv"},{"name","inv_0"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_9_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Iauthor.facts"},{"name","Iauthor"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_Iauthor);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Rule.facts"},{"name","Rule"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->readAll(*rel_2_Rule);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./precededBy.facts"},{"name","precededBy"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_precededBy);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_Iauthor");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_1_Iauthor);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_Rule");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->writeAll(*rel_2_Rule);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_precededBy");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_3_precededBy);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_4_author");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_author);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_9_inv_0");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_9_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
SymbolTable& getSymbolTable() override {
return symTable;
}
void executeSubroutine(std::string name, const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) override {
if (name == "author_1_negation_subproof") {
subproof_0(args, ret, err);
}
if (name == "author_1_subproof") {
subproof_1(args, ret, err);
}
if (name == "author_2_negation_subproof") {
subproof_2(args, ret, err);
}
if (name == "author_2_subproof") {
subproof_3(args, ret, err);
}
}
void subproof_0(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(194),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(194));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_precededBy_op_ctxt,rel_3_precededBy->createContext());
if(!rel_3_precededBy->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_precededBy_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(1));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back((args)[0]);
err.push_back(false);
ret.push_back((args)[2]);
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_author_op_ctxt,rel_4_author->createContext());
if(!rel_4_author->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_author_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(2));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back((args)[1]);
err.push_back(false);
ret.push_back((args)[2]);
err.push_back(false);
}
();return;
}
void subproof_1(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_author->empty()) && !(rel_3_precededBy->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(194),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_precededBy_op_ctxt,rel_3_precededBy->createContext());
CREATE_OP_CONTEXT(rel_4_author_op_ctxt,rel_4_author->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_precededBy->equalRange_1(key,READ_OP_CONTEXT(rel_3_precededBy_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_4_author->equalRange_3(key,READ_OP_CONTEXT(rel_4_author_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(194));
err.push_back(false);
ret.push_back(env0[1]);
err.push_back(false);
ret.push_back(env0[2]);
err.push_back(false);
ret.push_back(env1[0]);
err.push_back(false);
ret.push_back(env1[1]);
err.push_back(false);
ret.push_back(env1[2]);
err.push_back(false);
ret.push_back(env1[3]);
err.push_back(false);
ret.push_back(env2[0]);
err.push_back(false);
ret.push_back(env1[1]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
err.push_back(false);
ret.push_back(env1[0]);
err.push_back(false);
ret.push_back((args)[0]);
err.push_back(false);
ret.push_back(env2[0]);
err.push_back(false);
ret.push_back((args)[1]);
err.push_back(false);
ret.push_back(env0[2]);
err.push_back(false);
ret.push_back((args)[2]);
err.push_back(false);
ret.push_back(env1[3]);
err.push_back(false);
ret.push_back((args)[2]);
err.push_back(false);
ret.push_back(env2[3]);
err.push_back(false);
ret.push_back((args)[2]);
err.push_back(false);
}
}
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
return;
}
void subproof_2(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(172),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(172));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_precededBy_op_ctxt,rel_3_precededBy->createContext());
if(!rel_3_precededBy->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_precededBy_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(1));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back((args)[2]);
err.push_back(false);
ret.push_back((args)[1]);
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iauthor_op_ctxt,rel_1_Iauthor->createContext());
if(!rel_1_Iauthor->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iauthor_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(2));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back((args)[2]);
err.push_back(false);
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_3(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iauthor->empty()) && !(rel_3_precededBy->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(172),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iauthor_op_ctxt,rel_1_Iauthor->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_precededBy_op_ctxt,rel_3_precededBy->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_precededBy->equalRange_2(key,READ_OP_CONTEXT(rel_3_precededBy_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_1_Iauthor->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iauthor_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(172));
err.push_back(false);
ret.push_back(env0[1]);
err.push_back(false);
ret.push_back(env0[2]);
err.push_back(false);
ret.push_back(env1[0]);
err.push_back(false);
ret.push_back(env1[1]);
err.push_back(false);
ret.push_back(env1[2]);
err.push_back(false);
ret.push_back(env1[3]);
err.push_back(false);
ret.push_back(env1[0]);
err.push_back(false);
ret.push_back(env2[1]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
err.push_back(false);
ret.push_back(env2[1]);
err.push_back(false);
ret.push_back((args)[0]);
err.push_back(false);
ret.push_back(env1[1]);
err.push_back(false);
ret.push_back((args)[1]);
err.push_back(false);
ret.push_back(env0[2]);
err.push_back(false);
ret.push_back((args)[2]);
err.push_back(false);
ret.push_back(env1[3]);
err.push_back(false);
ret.push_back((args)[2]);
err.push_back(false);
ret.push_back(env2[3]);
err.push_back(false);
ret.push_back((args)[2]);
err.push_back(false);
}
}
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
return;
}
};
SouffleProgram *newInstance_program_small(){return new Sf_program_small;}
SymbolTable *getST_program_small(SouffleProgram *p){return &reinterpret_cast<Sf_program_small*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_program_small: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_program_small();
};
public:
factory_Sf_program_small() : ProgramFactory("program_small"){}
};
static factory_Sf_program_small __factory_Sf_program_small_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(sol_author.dl)",
R"(.)",
R"(.)",
false,
R"()",
5000,
-1);
if (!opt.parse(argc,argv)) return 1;
souffle::Sf_program_small obj;
#if defined(_OPENMP) 
obj.setNumThreads(opt.getNumJobs());

#endif
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
explain(obj, false);
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
