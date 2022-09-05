
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
struct t_btree_5__0_1_2_3_4__31 {
using t_tuple = Tuple<RamDomain, 5>;
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<0,1,2,3,4>>;
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
RamDomain data[5];
std::copy(ramDomain, ramDomain + 5, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3,RamDomain a4) {
RamDomain data[5] = {a0,a1,a2,a3,a4};
return insert(data);
}
template <typename T>
void insertAll(T& other) {
for (auto const& cur : other) {
insert(cur);
}
}
void insertAll(t_btree_5__0_1_2_3_4__31& other) {
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
range<t_ind_0::iterator> equalRange_31(const t_tuple& t, context& h) const {
auto pos = ind_0.find(t, h.hints_0);
auto fin = ind_0.end();
if (pos != fin) {fin = pos; ++fin;}
return make_range(pos, fin);
}
range<t_ind_0::iterator> equalRange_31(const t_tuple& t) const {
context h;
return equalRange_31(t, h);
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
o << prefix << "arity 5 direct b-tree index [0,1,2,3,4]: (hits/misses/total)\n";
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
	R"_(directed,v0,v2)_",
	R"_(created,v1,v2)_",
	R"_(created(v0,v1) :- 
   Rule(430),
   directed(v0,v2),
   created(v1,v2).)_",
	R"_(directed,v0,v1)_",
	R"_(created(v0,v1) :- 
   Rule(266),
   directed(v0,v1).)_",
	R"_(actedin,v2,v1)_",
	R"_(Icreated,v2,v0)_",
	R"_(created(v0,v1) :- 
   Rule(468),
   actedin(v2,v1),
   Icreated(v2,v0).)_",
	R"_(directed,v2,v1)_",
	R"_(created(v0,v1) :- 
   Rule(408),
   directed(v2,v1),
   Icreated(v2,v0).)_",
	R"_(produced,v0,v1)_",
	R"_(created(v0,v1) :- 
   Rule(264),
   produced(v0,v1).)_",
	R"_(produced,v2,v1)_",
	R"_(created(v0,v1) :- 
   Rule(336),
   produced(v2,v1),
   Icreated(v2,v0).)_",
	R"_(actedin,v0,v1)_",
	R"_(created(v0,v1) :- 
   Rule(268),
   actedin(v0,v1).)_",
	R"_(produced,v0,v2)_",
	R"_(created(v0,v1) :- 
   Rule(358),
   produced(v0,v2),
   created(v1,v2).)_",
	R"_(actedin,v0,v2)_",
	R"_(created(v0,v1) :- 
   Rule(490),
   actedin(v0,v2),
   created(v1,v2).)_",
};// -- Table: Icreated
std::unique_ptr<t_btree_4__0_1_2_3__1__3__15> rel_1_Icreated = std::make_unique<t_btree_4__0_1_2_3__1__3__15>();
souffle::RelationWrapper<0,t_btree_4__0_1_2_3__1__3__15,Tuple<RamDomain,4>,4> wrapper_rel_1_Icreated;
// -- Table: Rule
std::unique_ptr<t_btree_3__0_1_2__1__7> rel_2_Rule = std::make_unique<t_btree_3__0_1_2__1__7>();
souffle::RelationWrapper<1,t_btree_3__0_1_2__1__7,Tuple<RamDomain,3>,3> wrapper_rel_2_Rule;
// -- Table: actedin
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_3_actedin = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<2,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_3_actedin;
// -- Table: directed
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_4_directed = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<3,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_4_directed;
// -- Table: produced
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_5_produced = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<4,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_5_produced;
// -- Table: created
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_6_created = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<5,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_6_created;
// -- Table: @delta_created
std::unique_ptr<t_btree_4__1_0_2_3__2__15> rel_7_delta_created = std::make_unique<t_btree_4__1_0_2_3__2__15>();
// -- Table: @new_created
std::unique_ptr<t_btree_4__1_0_2_3__2__15> rel_8_new_created = std::make_unique<t_btree_4__1_0_2_3__2__15>();
// -- Table: created.@info.1
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_9_created_info_1 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<6,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_9_created_info_1;
// -- Table: created.@info.2
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_10_created_info_2 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<7,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_10_created_info_2;
// -- Table: created.@info.3
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_11_created_info_3 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<8,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_11_created_info_3;
// -- Table: created.@info.4
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_12_created_info_4 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<9,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_12_created_info_4;
// -- Table: created.@info.5
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_13_created_info_5 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<10,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_13_created_info_5;
// -- Table: created.@info.6
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_14_created_info_6 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<11,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_14_created_info_6;
// -- Table: created.@info.7
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_15_created_info_7 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<12,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_15_created_info_7;
// -- Table: created.@info.8
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_16_created_info_8 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<13,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_16_created_info_8;
// -- Table: created.@info.9
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_17_created_info_9 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<14,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_17_created_info_9;
// -- Table: inv_0
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_18_inv_0 = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<15,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4> wrapper_rel_18_inv_0;
public:
Sf_program_small() : 
wrapper_rel_1_Icreated(*rel_1_Icreated,symTable,"Icreated",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_2_Rule(*rel_2_Rule,symTable,"Rule",std::array<const char *,3>{{"i:number","i:number","i:number"}},std::array<const char *,3>{{"n","@rule_number","@level_number"}}),

wrapper_rel_3_actedin(*rel_3_actedin,symTable,"actedin",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_4_directed(*rel_4_directed,symTable,"directed",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_5_produced(*rel_5_produced,symTable,"produced",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_6_created(*rel_6_created,symTable,"created",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_9_created_info_1(*rel_9_created_info_1,symTable,"created.@info.1",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_10_created_info_2(*rel_10_created_info_2,symTable,"created.@info.2",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_11_created_info_3(*rel_11_created_info_3,symTable,"created.@info.3",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_12_created_info_4(*rel_12_created_info_4,symTable,"created.@info.4",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_13_created_info_5(*rel_13_created_info_5,symTable,"created.@info.5",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_14_created_info_6(*rel_14_created_info_6,symTable,"created.@info.6",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_15_created_info_7(*rel_15_created_info_7,symTable,"created.@info.7",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_16_created_info_8(*rel_16_created_info_8,symTable,"created.@info.8",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_17_created_info_9(*rel_17_created_info_9,symTable,"created.@info.9",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_18_inv_0(*rel_18_inv_0,symTable,"inv_0",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}){
addRelation("Icreated",&wrapper_rel_1_Icreated,true,false);
addRelation("Rule",&wrapper_rel_2_Rule,true,false);
addRelation("actedin",&wrapper_rel_3_actedin,true,false);
addRelation("directed",&wrapper_rel_4_directed,true,false);
addRelation("produced",&wrapper_rel_5_produced,true,false);
addRelation("created",&wrapper_rel_6_created,false,true);
addRelation("created.@info.1",&wrapper_rel_9_created_info_1,false,false);
addRelation("created.@info.2",&wrapper_rel_10_created_info_2,false,false);
addRelation("created.@info.3",&wrapper_rel_11_created_info_3,false,false);
addRelation("created.@info.4",&wrapper_rel_12_created_info_4,false,false);
addRelation("created.@info.5",&wrapper_rel_13_created_info_5,false,false);
addRelation("created.@info.6",&wrapper_rel_14_created_info_6,false,false);
addRelation("created.@info.7",&wrapper_rel_15_created_info_7,false,false);
addRelation("created.@info.8",&wrapper_rel_16_created_info_8,false,false);
addRelation("created.@info.9",&wrapper_rel_17_created_info_9,false,false);
addRelation("inv_0",&wrapper_rel_18_inv_0,false,true);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Icreated.facts"},{"name","Icreated"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_Icreated);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./actedin.facts"},{"name","actedin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_actedin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./directed.facts"},{"name","directed"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_4_directed);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./produced.facts"},{"name","produced"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_5_produced);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
SignalHandler::instance()->setMsg(R"_(created(v0,v1,2,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(266,_,@level_num_0),
   directed(v0,v1,_,@level_num_1).
in file /home/johannes/DatalogLearning/prosynth/filmsneg5/sol_created.dl [28:1-28:48])_");
if(!(rel_4_directed->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(266),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_directed_op_ctxt,rel_4_directed->createContext());
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_directed) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(2)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_6_created->insert(tuple,READ_OP_CONTEXT(rel_6_created_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(created(v0,v1,3,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(468,_,@level_num_0),
   actedin(v2,v1,_,@level_num_1),
   Icreated(v2,v0,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/filmsneg5/sol_created.dl [29:1-29:65])_");
if(!(rel_1_Icreated->empty()) && !(rel_3_actedin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(468),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Icreated_op_ctxt,rel_1_Icreated->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_actedin_op_ctxt,rel_3_actedin->createContext());
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_actedin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Icreated->equalRange_1(key,READ_OP_CONTEXT(rel_1_Icreated_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(3)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_created->insert(tuple,READ_OP_CONTEXT(rel_6_created_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(created(v0,v1,4,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(408,_,@level_num_0),
   directed(v2,v1,_,@level_num_1),
   Icreated(v2,v0,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/filmsneg5/sol_created.dl [30:1-30:66])_");
if(!(rel_1_Icreated->empty()) && !(rel_4_directed->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(408),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Icreated_op_ctxt,rel_1_Icreated->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_directed_op_ctxt,rel_4_directed->createContext());
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_directed) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Icreated->equalRange_1(key,READ_OP_CONTEXT(rel_1_Icreated_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(4)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_created->insert(tuple,READ_OP_CONTEXT(rel_6_created_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(created(v0,v1,5,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(264,_,@level_num_0),
   produced(v0,v1,_,@level_num_1).
in file /home/johannes/DatalogLearning/prosynth/filmsneg5/sol_created.dl [31:1-31:48])_");
if(!(rel_5_produced->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(264),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_produced_op_ctxt,rel_5_produced->createContext());
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_produced) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(5)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_6_created->insert(tuple,READ_OP_CONTEXT(rel_6_created_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(created(v0,v1,6,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(336,_,@level_num_0),
   produced(v2,v1,_,@level_num_1),
   Icreated(v2,v0,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/filmsneg5/sol_created.dl [32:1-32:66])_");
if(!(rel_1_Icreated->empty()) && !(rel_5_produced->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(336),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Icreated_op_ctxt,rel_1_Icreated->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_produced_op_ctxt,rel_5_produced->createContext());
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_produced) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Icreated->equalRange_1(key,READ_OP_CONTEXT(rel_1_Icreated_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(6)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_created->insert(tuple,READ_OP_CONTEXT(rel_6_created_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(created(v0,v1,7,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(268,_,@level_num_0),
   actedin(v0,v1,_,@level_num_1).
in file /home/johannes/DatalogLearning/prosynth/filmsneg5/sol_created.dl [33:1-33:47])_");
if(!(rel_3_actedin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(268),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_actedin_op_ctxt,rel_3_actedin->createContext());
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_actedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(7)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_6_created->insert(tuple,READ_OP_CONTEXT(rel_6_created_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
rel_7_delta_created->insertAll(*rel_6_created);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(created(v0,v1,1,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(430,_,@level_num_0),
   directed(v0,v2,_,@level_num_1),
   created(v1,v2,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/filmsneg5/sol_created.dl [27:1-27:65])_");
if(!(rel_7_delta_created->empty()) && !(rel_4_directed->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(430),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_directed_op_ctxt,rel_4_directed->createContext());
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
CREATE_OP_CONTEXT(rel_7_delta_created_op_ctxt,rel_7_delta_created->createContext());
CREATE_OP_CONTEXT(rel_8_new_created_op_ctxt,rel_8_new_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_directed) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_7_delta_created->equalRange_2(key,READ_OP_CONTEXT(rel_7_delta_created_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_6_created->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_6_created_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(1)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_8_new_created->insert(tuple,READ_OP_CONTEXT(rel_8_new_created_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(created(v0,v1,8,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(358,_,@level_num_0),
   produced(v0,v2,_,@level_num_1),
   created(v1,v2,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/filmsneg5/sol_created.dl [34:1-34:65])_");
if(!(rel_7_delta_created->empty()) && !(rel_5_produced->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(358),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_produced_op_ctxt,rel_5_produced->createContext());
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
CREATE_OP_CONTEXT(rel_7_delta_created_op_ctxt,rel_7_delta_created->createContext());
CREATE_OP_CONTEXT(rel_8_new_created_op_ctxt,rel_8_new_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_produced) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_7_delta_created->equalRange_2(key,READ_OP_CONTEXT(rel_7_delta_created_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_6_created->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_6_created_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(8)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_8_new_created->insert(tuple,READ_OP_CONTEXT(rel_8_new_created_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(created(v0,v1,9,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(490,_,@level_num_0),
   actedin(v0,v2,_,@level_num_1),
   created(v1,v2,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/filmsneg5/sol_created.dl [35:1-35:64])_");
if(!(rel_7_delta_created->empty()) && !(rel_3_actedin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(490),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_actedin_op_ctxt,rel_3_actedin->createContext());
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
CREATE_OP_CONTEXT(rel_7_delta_created_op_ctxt,rel_7_delta_created->createContext());
CREATE_OP_CONTEXT(rel_8_new_created_op_ctxt,rel_8_new_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_actedin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_7_delta_created->equalRange_2(key,READ_OP_CONTEXT(rel_7_delta_created_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_6_created->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_6_created_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(9)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_8_new_created->insert(tuple,READ_OP_CONTEXT(rel_8_new_created_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
if(rel_8_new_created->empty()) break;
rel_6_created->insertAll(*rel_8_new_created);
std::swap(rel_7_delta_created, rel_8_new_created);
rel_8_new_created->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_7_delta_created->purge();
if (!isHintsProfilingEnabled()) rel_8_new_created->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./created.csv"},{"name","created"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_6_created);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
SignalHandler::instance()->setMsg(R"_(created.@info.1(1,"v0,v1","Rule","directed,v0,v2","created,v1,v2","created(v0,v1) :- 
   Rule(430),
   directed(v0,v2),
   created(v1,v2).").
in file  [0:0-0:0])_");
rel_9_created_info_1->insert(RamDomain(1),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(3),RamDomain(4));
}();
/* END STRATUM 6 */
/* BEGIN STRATUM 7 */
[&]() {
SignalHandler::instance()->setMsg(R"_(created.@info.2(2,"v0,v1","Rule","directed,v0,v1","created(v0,v1) :- 
   Rule(266),
   directed(v0,v1).").
in file  [0:0-0:0])_");
rel_10_created_info_2->insert(RamDomain(2),RamDomain(0),RamDomain(1),RamDomain(5),RamDomain(6));
}();
/* END STRATUM 7 */
/* BEGIN STRATUM 8 */
[&]() {
SignalHandler::instance()->setMsg(R"_(created.@info.3(3,"v0,v1","Rule","actedin,v2,v1","Icreated,v2,v0","created(v0,v1) :- 
   Rule(468),
   actedin(v2,v1),
   Icreated(v2,v0).").
in file  [0:0-0:0])_");
rel_11_created_info_3->insert(RamDomain(3),RamDomain(0),RamDomain(1),RamDomain(7),RamDomain(8),RamDomain(9));
}();
/* END STRATUM 8 */
/* BEGIN STRATUM 9 */
[&]() {
SignalHandler::instance()->setMsg(R"_(created.@info.4(4,"v0,v1","Rule","directed,v2,v1","Icreated,v2,v0","created(v0,v1) :- 
   Rule(408),
   directed(v2,v1),
   Icreated(v2,v0).").
in file  [0:0-0:0])_");
rel_12_created_info_4->insert(RamDomain(4),RamDomain(0),RamDomain(1),RamDomain(10),RamDomain(8),RamDomain(11));
}();
/* END STRATUM 9 */
/* BEGIN STRATUM 10 */
[&]() {
SignalHandler::instance()->setMsg(R"_(created.@info.5(5,"v0,v1","Rule","produced,v0,v1","created(v0,v1) :- 
   Rule(264),
   produced(v0,v1).").
in file  [0:0-0:0])_");
rel_13_created_info_5->insert(RamDomain(5),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(13));
}();
/* END STRATUM 10 */
/* BEGIN STRATUM 11 */
[&]() {
SignalHandler::instance()->setMsg(R"_(created.@info.6(6,"v0,v1","Rule","produced,v2,v1","Icreated,v2,v0","created(v0,v1) :- 
   Rule(336),
   produced(v2,v1),
   Icreated(v2,v0).").
in file  [0:0-0:0])_");
rel_14_created_info_6->insert(RamDomain(6),RamDomain(0),RamDomain(1),RamDomain(14),RamDomain(8),RamDomain(15));
}();
/* END STRATUM 11 */
/* BEGIN STRATUM 12 */
[&]() {
SignalHandler::instance()->setMsg(R"_(created.@info.7(7,"v0,v1","Rule","actedin,v0,v1","created(v0,v1) :- 
   Rule(268),
   actedin(v0,v1).").
in file  [0:0-0:0])_");
rel_15_created_info_7->insert(RamDomain(7),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(17));
}();
/* END STRATUM 12 */
/* BEGIN STRATUM 13 */
[&]() {
SignalHandler::instance()->setMsg(R"_(created.@info.8(8,"v0,v1","Rule","produced,v0,v2","created,v1,v2","created(v0,v1) :- 
   Rule(358),
   produced(v0,v2),
   created(v1,v2).").
in file  [0:0-0:0])_");
rel_16_created_info_8->insert(RamDomain(8),RamDomain(0),RamDomain(1),RamDomain(18),RamDomain(3),RamDomain(19));
}();
/* END STRATUM 13 */
/* BEGIN STRATUM 14 */
[&]() {
SignalHandler::instance()->setMsg(R"_(created.@info.9(9,"v0,v1","Rule","actedin,v0,v2","created,v1,v2","created(v0,v1) :- 
   Rule(490),
   actedin(v0,v2),
   created(v1,v2).").
in file  [0:0-0:0])_");
rel_17_created_info_9->insert(RamDomain(9),RamDomain(0),RamDomain(1),RamDomain(20),RamDomain(3),RamDomain(21));
}();
/* END STRATUM 14 */
/* BEGIN STRATUM 15 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./inv_0.csv"},{"name","inv_0"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_18_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 15 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_Icreated:\n";
rel_1_Icreated->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_Rule:\n";
rel_2_Rule->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_actedin:\n";
rel_3_actedin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_directed:\n";
rel_4_directed->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_produced:\n";
rel_5_produced->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_created:\n";
rel_6_created->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_delta_created:\n";
rel_7_delta_created->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_new_created:\n";
rel_8_new_created->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_created_info_1:\n";
rel_9_created_info_1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_created_info_2:\n";
rel_10_created_info_2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_created_info_3:\n";
rel_11_created_info_3->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_created_info_4:\n";
rel_12_created_info_4->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_13_created_info_5:\n";
rel_13_created_info_5->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_14_created_info_6:\n";
rel_14_created_info_6->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_15_created_info_7:\n";
rel_15_created_info_7->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_16_created_info_8:\n";
rel_16_created_info_8->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_17_created_info_9:\n";
rel_17_created_info_9->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_18_inv_0:\n";
rel_18_inv_0->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./created.csv"},{"name","created"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_6_created);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./inv_0.csv"},{"name","inv_0"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_18_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Icreated.facts"},{"name","Icreated"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_Icreated);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Rule.facts"},{"name","Rule"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->readAll(*rel_2_Rule);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./actedin.facts"},{"name","actedin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_actedin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./directed.facts"},{"name","directed"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_4_directed);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./produced.facts"},{"name","produced"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_5_produced);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_Icreated");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_1_Icreated);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_Rule");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->writeAll(*rel_2_Rule);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_actedin");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_3_actedin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_4_directed");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_directed);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_5_produced");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_5_produced);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_6_created");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_6_created);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_18_inv_0");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_18_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
SymbolTable& getSymbolTable() override {
return symTable;
}
void executeSubroutine(std::string name, const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) override {
if (name == "created_1_negation_subproof") {
subproof_0(args, ret, err);
}
if (name == "created_1_subproof") {
subproof_1(args, ret, err);
}
if (name == "created_2_negation_subproof") {
subproof_2(args, ret, err);
}
if (name == "created_2_subproof") {
subproof_3(args, ret, err);
}
if (name == "created_3_negation_subproof") {
subproof_4(args, ret, err);
}
if (name == "created_3_subproof") {
subproof_5(args, ret, err);
}
if (name == "created_4_negation_subproof") {
subproof_6(args, ret, err);
}
if (name == "created_4_subproof") {
subproof_7(args, ret, err);
}
if (name == "created_5_negation_subproof") {
subproof_8(args, ret, err);
}
if (name == "created_5_subproof") {
subproof_9(args, ret, err);
}
if (name == "created_6_negation_subproof") {
subproof_10(args, ret, err);
}
if (name == "created_6_subproof") {
subproof_11(args, ret, err);
}
if (name == "created_7_negation_subproof") {
subproof_12(args, ret, err);
}
if (name == "created_7_subproof") {
subproof_13(args, ret, err);
}
if (name == "created_8_negation_subproof") {
subproof_14(args, ret, err);
}
if (name == "created_8_subproof") {
subproof_15(args, ret, err);
}
if (name == "created_9_negation_subproof") {
subproof_16(args, ret, err);
}
if (name == "created_9_subproof") {
subproof_17(args, ret, err);
}
}
void subproof_0(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(430),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(430));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_directed_op_ctxt,rel_4_directed->createContext());
if(!rel_4_directed->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_directed_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
if(!rel_6_created->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_6_created_op_ctxt)).empty()) {
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
if(!(rel_6_created->empty()) && !(rel_4_directed->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(430),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_directed_op_ctxt,rel_4_directed->createContext());
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_4_directed->equalRange_1(key,READ_OP_CONTEXT(rel_4_directed_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_6_created->equalRange_3(key,READ_OP_CONTEXT(rel_6_created_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(430));
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
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(266),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(266));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_directed_op_ctxt,rel_4_directed->createContext());
if(!rel_4_directed->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_directed_op_ctxt)).empty()) {
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
ret.push_back((args)[1]);
err.push_back(false);
}
();return;
}
void subproof_3(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_directed->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(266),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_directed_op_ctxt,rel_4_directed->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_4_directed->equalRange_3(key,READ_OP_CONTEXT(rel_4_directed_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(266));
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
void subproof_4(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(468),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(468));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_actedin_op_ctxt,rel_3_actedin->createContext());
if(!rel_3_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_actedin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Icreated_op_ctxt,rel_1_Icreated->createContext());
if(!rel_1_Icreated->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Icreated_op_ctxt)).empty()) {
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
void subproof_5(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Icreated->empty()) && !(rel_3_actedin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(468),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Icreated_op_ctxt,rel_1_Icreated->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_actedin_op_ctxt,rel_3_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_actedin->equalRange_2(key,READ_OP_CONTEXT(rel_3_actedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_1_Icreated->equalRange_3(key,READ_OP_CONTEXT(rel_1_Icreated_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(468));
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
void subproof_6(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(408),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(408));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_directed_op_ctxt,rel_4_directed->createContext());
if(!rel_4_directed->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_directed_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Icreated_op_ctxt,rel_1_Icreated->createContext());
if(!rel_1_Icreated->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Icreated_op_ctxt)).empty()) {
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
void subproof_7(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Icreated->empty()) && !(rel_4_directed->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(408),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Icreated_op_ctxt,rel_1_Icreated->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_directed_op_ctxt,rel_4_directed->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_4_directed->equalRange_2(key,READ_OP_CONTEXT(rel_4_directed_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_1_Icreated->equalRange_3(key,READ_OP_CONTEXT(rel_1_Icreated_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(408));
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
void subproof_8(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(264),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(264));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_5_produced_op_ctxt,rel_5_produced->createContext());
if(!rel_5_produced->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_5_produced_op_ctxt)).empty()) {
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
ret.push_back((args)[1]);
err.push_back(false);
}
();return;
}
void subproof_9(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_produced->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(264),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_produced_op_ctxt,rel_5_produced->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_5_produced->equalRange_3(key,READ_OP_CONTEXT(rel_5_produced_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(264));
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
void subproof_10(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(336),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(336));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_5_produced_op_ctxt,rel_5_produced->createContext());
if(!rel_5_produced->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_5_produced_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Icreated_op_ctxt,rel_1_Icreated->createContext());
if(!rel_1_Icreated->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Icreated_op_ctxt)).empty()) {
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
void subproof_11(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Icreated->empty()) && !(rel_5_produced->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(336),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Icreated_op_ctxt,rel_1_Icreated->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_produced_op_ctxt,rel_5_produced->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_5_produced->equalRange_2(key,READ_OP_CONTEXT(rel_5_produced_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_1_Icreated->equalRange_3(key,READ_OP_CONTEXT(rel_1_Icreated_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(336));
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
void subproof_12(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(268),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(268));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_actedin_op_ctxt,rel_3_actedin->createContext());
if(!rel_3_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_actedin_op_ctxt)).empty()) {
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
ret.push_back((args)[1]);
err.push_back(false);
}
();return;
}
void subproof_13(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_actedin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(268),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_actedin_op_ctxt,rel_3_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_actedin->equalRange_3(key,READ_OP_CONTEXT(rel_3_actedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(268));
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
void subproof_14(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(358),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(358));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_5_produced_op_ctxt,rel_5_produced->createContext());
if(!rel_5_produced->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_5_produced_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
if(!rel_6_created->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_6_created_op_ctxt)).empty()) {
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
void subproof_15(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_6_created->empty()) && !(rel_5_produced->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(358),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_produced_op_ctxt,rel_5_produced->createContext());
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_5_produced->equalRange_1(key,READ_OP_CONTEXT(rel_5_produced_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_6_created->equalRange_3(key,READ_OP_CONTEXT(rel_6_created_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(358));
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
void subproof_16(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(490),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(490));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_actedin_op_ctxt,rel_3_actedin->createContext());
if(!rel_3_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_actedin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
if(!rel_6_created->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_6_created_op_ctxt)).empty()) {
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
void subproof_17(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_6_created->empty()) && !(rel_3_actedin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(490),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_actedin_op_ctxt,rel_3_actedin->createContext());
CREATE_OP_CONTEXT(rel_6_created_op_ctxt,rel_6_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_actedin->equalRange_1(key,READ_OP_CONTEXT(rel_3_actedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_6_created->equalRange_3(key,READ_OP_CONTEXT(rel_6_created_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(490));
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
souffle::CmdOptions opt(R"(sol_created.dl)",
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
