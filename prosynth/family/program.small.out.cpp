
#include "souffle/CompiledSouffle.h"
#include <mutex>
#include "souffle/Explain.h"

extern "C" {
}

namespace souffle {
using namespace ram;
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
struct t_btree_4__1_0_3_2__0_1_2_3__1__2__15 {
using t_tuple = Tuple<RamDomain, 4>;
struct updater_t_btree_4__1_0_3_2__0_1_2_3__1__2__15 {
void update(t_tuple& old_t, const t_tuple& new_t) {
old_t[2] = new_t[2];
old_t[3] = new_t[3];
}
};
using t_ind_0 = btree_set<t_tuple, index_utils::comparator<1,0,3,2>, std::allocator<t_tuple>, 256, typename souffle::detail::default_strategy<t_tuple>::type, index_utils::comparator<1,0>, updater_t_btree_4__1_0_3_2__0_1_2_3__1__2__15>;
t_ind_0 ind_0;
using t_ind_1 = btree_set<t_tuple, index_utils::comparator<0,1,2,3>, std::allocator<t_tuple>, 256, typename souffle::detail::default_strategy<t_tuple>::type, index_utils::comparator<0,1>, updater_t_btree_4__1_0_3_2__0_1_2_3__1__2__15>;
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
void insertAll(t_btree_4__1_0_3_2__0_1_2_3__1__2__15& other) {
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
range<t_ind_1::iterator> equalRange_1(const t_tuple& t, context& h) const {
t_tuple low(t); t_tuple high(t);
low[1] = MIN_RAM_DOMAIN;
high[1] = MAX_RAM_DOMAIN;
low[2] = MIN_RAM_DOMAIN;
high[2] = MAX_RAM_DOMAIN;
low[3] = MIN_RAM_DOMAIN;
high[3] = MAX_RAM_DOMAIN;
return make_range(ind_1.lower_bound(low, h.hints_1), ind_1.upper_bound(high, h.hints_1));
}
range<t_ind_1::iterator> equalRange_1(const t_tuple& t) const {
context h;
return equalRange_1(t, h);
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
o << prefix << "arity 4 direct b-tree index [1,0,3,2]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_0.inserts.getHits() << "/" << stats_0.inserts.getMisses() << "/" << stats_0.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_0.contains.getHits() << "/" << stats_0.contains.getMisses() << "/" << stats_0.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_0.lower_bound.getHits() << "/" << stats_0.lower_bound.getMisses() << "/" << stats_0.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_0.upper_bound.getHits() << "/" << stats_0.upper_bound.getMisses() << "/" << stats_0.upper_bound.getAccesses() << "\n";
const auto& stats_1 = ind_1.getHintStatistics();
o << prefix << "arity 4 direct b-tree index [0,1,2,3]: (hits/misses/total)\n";
o << prefix << "Insert: " << stats_1.inserts.getHits() << "/" << stats_1.inserts.getMisses() << "/" << stats_1.inserts.getAccesses() << "\n";
o << prefix << "Contains: " << stats_1.contains.getHits() << "/" << stats_1.contains.getMisses() << "/" << stats_1.contains.getAccesses() << "\n";
o << prefix << "Lower-bound: " << stats_1.lower_bound.getHits() << "/" << stats_1.lower_bound.getMisses() << "/" << stats_1.lower_bound.getAccesses() << "\n";
o << prefix << "Upper-bound: " << stats_1.upper_bound.getHits() << "/" << stats_1.upper_bound.getMisses() << "/" << stats_1.upper_bound.getAccesses() << "\n";
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
	R"_(ismarriedto,v0,v2)_",
	R"_(ismarriedto,v1,v2)_",
	R"_(haschild(v0,v1) :- 
   Rule(94),
   ismarriedto(v0,v2),
   ismarriedto(v1,v2).)_",
	R"_(ismarriedto,v2,v0)_",
	R"_(haschild,v1,v2)_",
	R"_(haschild(v0,v1) :- 
   Rule(128),
   ismarriedto(v2,v0),
   haschild(v1,v2).)_",
	R"_(ismarriedto,v2,v1)_",
	R"_(Ihaschild,v2,v0)_",
	R"_(haschild(v0,v1) :- 
   Rule(108),
   ismarriedto(v2,v1),
   Ihaschild(v2,v0).)_",
	R"_(haschild,v2,v0)_",
	R"_(haschild(v0,v1) :- 
   Rule(127),
   ismarriedto(v1,v2),
   haschild(v2,v0).)_",
	R"_(haschild(v0,v1) :- 
   Rule(103),
   ismarriedto(v1,v2),
   Ihaschild(v2,v0).)_",
	R"_(Ihaschild,v2,v1)_",
	R"_(haschild(v0,v1) :- 
   Rule(105),
   ismarriedto(v2,v0),
   Ihaschild(v2,v1).)_",
	R"_(ismarriedto,v0,v1)_",
	R"_(haschild(v0,v1) :- 
   Rule(78),
   ismarriedto(v0,v1).)_",
	R"_(Ihaschild,v1,v2)_",
	R"_(haschild(v0,v1) :- 
   Rule(104),
   ismarriedto(v2,v0),
   Ihaschild(v1,v2).)_",
	R"_(haschild(v0,v1) :- 
   Rule(130),
   ismarriedto(v0,v2),
   haschild(v1,v2).)_",
};// -- Table: Ihaschild
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_1_Ihaschild = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<0,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_1_Ihaschild;
// -- Table: Rule
std::unique_ptr<t_btree_3__0_1_2__1__7> rel_2_Rule = std::make_unique<t_btree_3__0_1_2__1__7>();
souffle::RelationWrapper<1,t_btree_3__0_1_2__1__7,Tuple<RamDomain,3>,3> wrapper_rel_2_Rule;
// -- Table: ismarriedto
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_3_ismarriedto = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<2,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_3_ismarriedto;
// -- Table: haschild
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_4_haschild = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<3,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_4_haschild;
// -- Table: @delta_haschild
std::unique_ptr<t_btree_4__1_0_3_2__0_1_2_3__1__2__15> rel_5_delta_haschild = std::make_unique<t_btree_4__1_0_3_2__0_1_2_3__1__2__15>();
// -- Table: @new_haschild
std::unique_ptr<t_btree_4__1_0_3_2__0_1_2_3__1__2__15> rel_6_new_haschild = std::make_unique<t_btree_4__1_0_3_2__0_1_2_3__1__2__15>();
// -- Table: haschild.@info.1
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_7_haschild_info_1 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<4,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_7_haschild_info_1;
// -- Table: haschild.@info.2
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_8_haschild_info_2 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<5,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_8_haschild_info_2;
// -- Table: haschild.@info.3
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_9_haschild_info_3 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<6,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_9_haschild_info_3;
// -- Table: haschild.@info.4
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_10_haschild_info_4 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<7,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_10_haschild_info_4;
// -- Table: haschild.@info.5
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_11_haschild_info_5 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<8,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_11_haschild_info_5;
// -- Table: haschild.@info.6
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_12_haschild_info_6 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<9,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_12_haschild_info_6;
// -- Table: haschild.@info.7
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_13_haschild_info_7 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<10,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_13_haschild_info_7;
// -- Table: haschild.@info.8
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_14_haschild_info_8 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<11,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_14_haschild_info_8;
// -- Table: haschild.@info.9
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_15_haschild_info_9 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<12,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_15_haschild_info_9;
// -- Table: inv_0
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_16_inv_0 = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<13,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4> wrapper_rel_16_inv_0;
public:
Sf_program_small() : 
wrapper_rel_1_Ihaschild(*rel_1_Ihaschild,symTable,"Ihaschild",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_2_Rule(*rel_2_Rule,symTable,"Rule",std::array<const char *,3>{{"i:number","i:number","i:number"}},std::array<const char *,3>{{"n","@rule_number","@level_number"}}),

wrapper_rel_3_ismarriedto(*rel_3_ismarriedto,symTable,"ismarriedto",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_4_haschild(*rel_4_haschild,symTable,"haschild",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_7_haschild_info_1(*rel_7_haschild_info_1,symTable,"haschild.@info.1",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_8_haschild_info_2(*rel_8_haschild_info_2,symTable,"haschild.@info.2",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_9_haschild_info_3(*rel_9_haschild_info_3,symTable,"haschild.@info.3",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_10_haschild_info_4(*rel_10_haschild_info_4,symTable,"haschild.@info.4",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_11_haschild_info_5(*rel_11_haschild_info_5,symTable,"haschild.@info.5",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_12_haschild_info_6(*rel_12_haschild_info_6,symTable,"haschild.@info.6",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_13_haschild_info_7(*rel_13_haschild_info_7,symTable,"haschild.@info.7",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_14_haschild_info_8(*rel_14_haschild_info_8,symTable,"haschild.@info.8",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_15_haschild_info_9(*rel_15_haschild_info_9,symTable,"haschild.@info.9",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_16_inv_0(*rel_16_inv_0,symTable,"inv_0",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}){
addRelation("Ihaschild",&wrapper_rel_1_Ihaschild,true,false);
addRelation("Rule",&wrapper_rel_2_Rule,true,false);
addRelation("ismarriedto",&wrapper_rel_3_ismarriedto,true,false);
addRelation("haschild",&wrapper_rel_4_haschild,false,true);
addRelation("haschild.@info.1",&wrapper_rel_7_haschild_info_1,false,false);
addRelation("haschild.@info.2",&wrapper_rel_8_haschild_info_2,false,false);
addRelation("haschild.@info.3",&wrapper_rel_9_haschild_info_3,false,false);
addRelation("haschild.@info.4",&wrapper_rel_10_haschild_info_4,false,false);
addRelation("haschild.@info.5",&wrapper_rel_11_haschild_info_5,false,false);
addRelation("haschild.@info.6",&wrapper_rel_12_haschild_info_6,false,false);
addRelation("haschild.@info.7",&wrapper_rel_13_haschild_info_7,false,false);
addRelation("haschild.@info.8",&wrapper_rel_14_haschild_info_8,false,false);
addRelation("haschild.@info.9",&wrapper_rel_15_haschild_info_9,false,false);
addRelation("inv_0",&wrapper_rel_16_inv_0,false,true);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Ihaschild.facts"},{"name","Ihaschild"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_Ihaschild);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./ismarriedto.facts"},{"name","ismarriedto"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_ismarriedto);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
SignalHandler::instance()->setMsg(R"_(haschild(v0,v1,1,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(94,_,@level_num_0),
   ismarriedto(v0,v2,_,@level_num_1),
   ismarriedto(v1,v2,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/family/sol_haschild.dl [18:1-18:72])_");
if(!(rel_3_ismarriedto->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(94),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_ismarriedto) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_3_ismarriedto->equalRange_2(key,READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(1)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_haschild->insert(tuple,READ_OP_CONTEXT(rel_4_haschild_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(haschild(v0,v1,3,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(108,_,@level_num_0),
   ismarriedto(v2,v1,_,@level_num_1),
   Ihaschild(v2,v0,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/family/sol_haschild.dl [20:1-20:71])_");
if(!(rel_1_Ihaschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(108),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Ihaschild_op_ctxt,rel_1_Ihaschild->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_ismarriedto) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Ihaschild->equalRange_1(key,READ_OP_CONTEXT(rel_1_Ihaschild_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(3)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_haschild->insert(tuple,READ_OP_CONTEXT(rel_4_haschild_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(haschild(v0,v1,5,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(103,_,@level_num_0),
   ismarriedto(v1,v2,_,@level_num_1),
   Ihaschild(v2,v0,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/family/sol_haschild.dl [22:1-22:71])_");
if(!(rel_1_Ihaschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(103),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Ihaschild_op_ctxt,rel_1_Ihaschild->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_ismarriedto) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_1_Ihaschild->equalRange_1(key,READ_OP_CONTEXT(rel_1_Ihaschild_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(5)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_haschild->insert(tuple,READ_OP_CONTEXT(rel_4_haschild_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(haschild(v0,v1,6,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(105,_,@level_num_0),
   ismarriedto(v2,v0,_,@level_num_1),
   Ihaschild(v2,v1,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/family/sol_haschild.dl [23:1-23:71])_");
if(!(rel_1_Ihaschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(105),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Ihaschild_op_ctxt,rel_1_Ihaschild->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_ismarriedto) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Ihaschild->equalRange_1(key,READ_OP_CONTEXT(rel_1_Ihaschild_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(6)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_haschild->insert(tuple,READ_OP_CONTEXT(rel_4_haschild_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(haschild(v0,v1,7,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(78,_,@level_num_0),
   ismarriedto(v0,v1,_,@level_num_1).
in file /home/johannes/DatalogLearning/prosynth/family/sol_haschild.dl [24:1-24:51])_");
if(!(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(78),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_ismarriedto) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(7)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_4_haschild->insert(tuple,READ_OP_CONTEXT(rel_4_haschild_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(haschild(v0,v1,8,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(104,_,@level_num_0),
   ismarriedto(v2,v0,_,@level_num_1),
   Ihaschild(v1,v2,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/family/sol_haschild.dl [25:1-25:71])_");
if(!(rel_1_Ihaschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(104),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Ihaschild_op_ctxt,rel_1_Ihaschild->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_ismarriedto) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_1_Ihaschild->equalRange_2(key,READ_OP_CONTEXT(rel_1_Ihaschild_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(8)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_haschild->insert(tuple,READ_OP_CONTEXT(rel_4_haschild_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
rel_5_delta_haschild->insertAll(*rel_4_haschild);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(haschild(v0,v1,2,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(128,_,@level_num_0),
   ismarriedto(v2,v0,_,@level_num_1),
   haschild(v1,v2,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/family/sol_haschild.dl [19:1-19:70])_");
if(!(rel_5_delta_haschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(128),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
CREATE_OP_CONTEXT(rel_5_delta_haschild_op_ctxt,rel_5_delta_haschild->createContext());
CREATE_OP_CONTEXT(rel_6_new_haschild_op_ctxt,rel_6_new_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_ismarriedto) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_5_delta_haschild->equalRange_2(key,READ_OP_CONTEXT(rel_5_delta_haschild_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_haschild->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_4_haschild_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(2)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_haschild->insert(tuple,READ_OP_CONTEXT(rel_6_new_haschild_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(haschild(v0,v1,4,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(127,_,@level_num_0),
   ismarriedto(v1,v2,_,@level_num_1),
   haschild(v2,v0,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/family/sol_haschild.dl [21:1-21:70])_");
if(!(rel_5_delta_haschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(127),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
CREATE_OP_CONTEXT(rel_5_delta_haschild_op_ctxt,rel_5_delta_haschild->createContext());
CREATE_OP_CONTEXT(rel_6_new_haschild_op_ctxt,rel_6_new_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_ismarriedto) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_5_delta_haschild->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_haschild_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_haschild->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_4_haschild_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(4)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_haschild->insert(tuple,READ_OP_CONTEXT(rel_6_new_haschild_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(haschild(v0,v1,9,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(130,_,@level_num_0),
   ismarriedto(v0,v2,_,@level_num_1),
   haschild(v1,v2,_,@level_num_2).
in file /home/johannes/DatalogLearning/prosynth/family/sol_haschild.dl [26:1-26:70])_");
if(!(rel_5_delta_haschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(130),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
CREATE_OP_CONTEXT(rel_5_delta_haschild_op_ctxt,rel_5_delta_haschild->createContext());
CREATE_OP_CONTEXT(rel_6_new_haschild_op_ctxt,rel_6_new_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_ismarriedto) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_5_delta_haschild->equalRange_2(key,READ_OP_CONTEXT(rel_5_delta_haschild_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_haschild->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_4_haschild_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(9)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_haschild->insert(tuple,READ_OP_CONTEXT(rel_6_new_haschild_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
if(rel_6_new_haschild->empty()) break;
rel_4_haschild->insertAll(*rel_6_new_haschild);
std::swap(rel_5_delta_haschild, rel_6_new_haschild);
rel_6_new_haschild->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_5_delta_haschild->purge();
if (!isHintsProfilingEnabled()) rel_6_new_haschild->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./haschild.csv"},{"name","haschild"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_haschild);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
SignalHandler::instance()->setMsg(R"_(haschild.@info.1(1,"v0,v1","Rule","ismarriedto,v0,v2","ismarriedto,v1,v2","haschild(v0,v1) :- 
   Rule(94),
   ismarriedto(v0,v2),
   ismarriedto(v1,v2).").
in file  [0:0-0:0])_");
rel_7_haschild_info_1->insert(RamDomain(1),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(3),RamDomain(4));
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
SignalHandler::instance()->setMsg(R"_(haschild.@info.2(2,"v0,v1","Rule","ismarriedto,v2,v0","haschild,v1,v2","haschild(v0,v1) :- 
   Rule(128),
   ismarriedto(v2,v0),
   haschild(v1,v2).").
in file  [0:0-0:0])_");
rel_8_haschild_info_2->insert(RamDomain(2),RamDomain(0),RamDomain(1),RamDomain(5),RamDomain(6),RamDomain(7));
}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
SignalHandler::instance()->setMsg(R"_(haschild.@info.3(3,"v0,v1","Rule","ismarriedto,v2,v1","Ihaschild,v2,v0","haschild(v0,v1) :- 
   Rule(108),
   ismarriedto(v2,v1),
   Ihaschild(v2,v0).").
in file  [0:0-0:0])_");
rel_9_haschild_info_3->insert(RamDomain(3),RamDomain(0),RamDomain(1),RamDomain(8),RamDomain(9),RamDomain(10));
}();
/* END STRATUM 6 */
/* BEGIN STRATUM 7 */
[&]() {
SignalHandler::instance()->setMsg(R"_(haschild.@info.4(4,"v0,v1","Rule","ismarriedto,v1,v2","haschild,v2,v0","haschild(v0,v1) :- 
   Rule(127),
   ismarriedto(v1,v2),
   haschild(v2,v0).").
in file  [0:0-0:0])_");
rel_10_haschild_info_4->insert(RamDomain(4),RamDomain(0),RamDomain(1),RamDomain(3),RamDomain(11),RamDomain(12));
}();
/* END STRATUM 7 */
/* BEGIN STRATUM 8 */
[&]() {
SignalHandler::instance()->setMsg(R"_(haschild.@info.5(5,"v0,v1","Rule","ismarriedto,v1,v2","Ihaschild,v2,v0","haschild(v0,v1) :- 
   Rule(103),
   ismarriedto(v1,v2),
   Ihaschild(v2,v0).").
in file  [0:0-0:0])_");
rel_11_haschild_info_5->insert(RamDomain(5),RamDomain(0),RamDomain(1),RamDomain(3),RamDomain(9),RamDomain(13));
}();
/* END STRATUM 8 */
/* BEGIN STRATUM 9 */
[&]() {
SignalHandler::instance()->setMsg(R"_(haschild.@info.6(6,"v0,v1","Rule","ismarriedto,v2,v0","Ihaschild,v2,v1","haschild(v0,v1) :- 
   Rule(105),
   ismarriedto(v2,v0),
   Ihaschild(v2,v1).").
in file  [0:0-0:0])_");
rel_12_haschild_info_6->insert(RamDomain(6),RamDomain(0),RamDomain(1),RamDomain(5),RamDomain(14),RamDomain(15));
}();
/* END STRATUM 9 */
/* BEGIN STRATUM 10 */
[&]() {
SignalHandler::instance()->setMsg(R"_(haschild.@info.7(7,"v0,v1","Rule","ismarriedto,v0,v1","haschild(v0,v1) :- 
   Rule(78),
   ismarriedto(v0,v1).").
in file  [0:0-0:0])_");
rel_13_haschild_info_7->insert(RamDomain(7),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(17));
}();
/* END STRATUM 10 */
/* BEGIN STRATUM 11 */
[&]() {
SignalHandler::instance()->setMsg(R"_(haschild.@info.8(8,"v0,v1","Rule","ismarriedto,v2,v0","Ihaschild,v1,v2","haschild(v0,v1) :- 
   Rule(104),
   ismarriedto(v2,v0),
   Ihaschild(v1,v2).").
in file  [0:0-0:0])_");
rel_14_haschild_info_8->insert(RamDomain(8),RamDomain(0),RamDomain(1),RamDomain(5),RamDomain(18),RamDomain(19));
}();
/* END STRATUM 11 */
/* BEGIN STRATUM 12 */
[&]() {
SignalHandler::instance()->setMsg(R"_(haschild.@info.9(9,"v0,v1","Rule","ismarriedto,v0,v2","haschild,v1,v2","haschild(v0,v1) :- 
   Rule(130),
   ismarriedto(v0,v2),
   haschild(v1,v2).").
in file  [0:0-0:0])_");
rel_15_haschild_info_9->insert(RamDomain(9),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(6),RamDomain(20));
}();
/* END STRATUM 12 */
/* BEGIN STRATUM 13 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./inv_0.csv"},{"name","inv_0"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_16_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 13 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_Ihaschild:\n";
rel_1_Ihaschild->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_Rule:\n";
rel_2_Rule->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_ismarriedto:\n";
rel_3_ismarriedto->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_haschild:\n";
rel_4_haschild->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_delta_haschild:\n";
rel_5_delta_haschild->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_new_haschild:\n";
rel_6_new_haschild->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_haschild_info_1:\n";
rel_7_haschild_info_1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_haschild_info_2:\n";
rel_8_haschild_info_2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_haschild_info_3:\n";
rel_9_haschild_info_3->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_haschild_info_4:\n";
rel_10_haschild_info_4->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_haschild_info_5:\n";
rel_11_haschild_info_5->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_haschild_info_6:\n";
rel_12_haschild_info_6->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_13_haschild_info_7:\n";
rel_13_haschild_info_7->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_14_haschild_info_8:\n";
rel_14_haschild_info_8->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_15_haschild_info_9:\n";
rel_15_haschild_info_9->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_16_inv_0:\n";
rel_16_inv_0->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./haschild.csv"},{"name","haschild"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_haschild);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./inv_0.csv"},{"name","inv_0"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_16_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Ihaschild.facts"},{"name","Ihaschild"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_Ihaschild);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Rule.facts"},{"name","Rule"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->readAll(*rel_2_Rule);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./ismarriedto.facts"},{"name","ismarriedto"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_ismarriedto);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_Ihaschild");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_1_Ihaschild);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_Rule");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->writeAll(*rel_2_Rule);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_ismarriedto");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_3_ismarriedto);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_4_haschild");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_haschild);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_16_inv_0");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_16_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
SymbolTable& getSymbolTable() override {
return symTable;
}
void executeSubroutine(std::string name, const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) override {
if (name == "haschild_1_negation_subproof") {
subproof_0(args, ret, err);
}
if (name == "haschild_1_subproof") {
subproof_1(args, ret, err);
}
if (name == "haschild_2_negation_subproof") {
subproof_2(args, ret, err);
}
if (name == "haschild_2_subproof") {
subproof_3(args, ret, err);
}
if (name == "haschild_3_negation_subproof") {
subproof_4(args, ret, err);
}
if (name == "haschild_3_subproof") {
subproof_5(args, ret, err);
}
if (name == "haschild_4_negation_subproof") {
subproof_6(args, ret, err);
}
if (name == "haschild_4_subproof") {
subproof_7(args, ret, err);
}
if (name == "haschild_5_negation_subproof") {
subproof_8(args, ret, err);
}
if (name == "haschild_5_subproof") {
subproof_9(args, ret, err);
}
if (name == "haschild_6_negation_subproof") {
subproof_10(args, ret, err);
}
if (name == "haschild_6_subproof") {
subproof_11(args, ret, err);
}
if (name == "haschild_7_negation_subproof") {
subproof_12(args, ret, err);
}
if (name == "haschild_7_subproof") {
subproof_13(args, ret, err);
}
if (name == "haschild_8_negation_subproof") {
subproof_14(args, ret, err);
}
if (name == "haschild_8_subproof") {
subproof_15(args, ret, err);
}
if (name == "haschild_9_negation_subproof") {
subproof_16(args, ret, err);
}
if (name == "haschild_9_subproof") {
subproof_17(args, ret, err);
}
}
void subproof_0(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(94),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(94));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
if(!rel_3_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
if(!rel_3_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt)).empty()) {
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
if(!(rel_3_ismarriedto->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(94),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_ismarriedto->equalRange_1(key,READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_3_ismarriedto->equalRange_3(key,READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(94));
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
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(128),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(128));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
if(!rel_3_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
if(!rel_4_haschild->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_haschild_op_ctxt)).empty()) {
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
void subproof_3(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_haschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(128),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_ismarriedto->equalRange_2(key,READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_4_haschild->equalRange_3(key,READ_OP_CONTEXT(rel_4_haschild_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(128));
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
ret.push_back(env1[0]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
err.push_back(false);
ret.push_back(env1[1]);
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
void subproof_4(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(108),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(108));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
if(!rel_3_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Ihaschild_op_ctxt,rel_1_Ihaschild->createContext());
if(!rel_1_Ihaschild->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Ihaschild_op_ctxt)).empty()) {
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
if(!(rel_1_Ihaschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(108),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Ihaschild_op_ctxt,rel_1_Ihaschild->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_ismarriedto->equalRange_2(key,READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_1_Ihaschild->equalRange_3(key,READ_OP_CONTEXT(rel_1_Ihaschild_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(108));
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
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(127),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(127));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
if(!rel_3_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(1));
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
();[&](){
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
if(!rel_4_haschild->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_haschild_op_ctxt)).empty()) {
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
if(!(rel_4_haschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(127),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_ismarriedto->equalRange_1(key,READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_4_haschild->equalRange_3(key,READ_OP_CONTEXT(rel_4_haschild_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(127));
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
ret.push_back(env1[1]);
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
ret.push_back(env1[0]);
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
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(103),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(103));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
if(!rel_3_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(1));
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
();[&](){
CREATE_OP_CONTEXT(rel_1_Ihaschild_op_ctxt,rel_1_Ihaschild->createContext());
if(!rel_1_Ihaschild->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Ihaschild_op_ctxt)).empty()) {
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
void subproof_9(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Ihaschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(103),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Ihaschild_op_ctxt,rel_1_Ihaschild->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_ismarriedto->equalRange_1(key,READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_1_Ihaschild->equalRange_3(key,READ_OP_CONTEXT(rel_1_Ihaschild_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(103));
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
ret.push_back(env1[1]);
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
ret.push_back(env1[0]);
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
void subproof_10(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(105),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(105));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
if(!rel_3_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Ihaschild_op_ctxt,rel_1_Ihaschild->createContext());
if(!rel_1_Ihaschild->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_1_Ihaschild_op_ctxt)).empty()) {
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
ret.push_back((args)[1]);
err.push_back(false);
}
();return;
}
void subproof_11(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Ihaschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(105),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Ihaschild_op_ctxt,rel_1_Ihaschild->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_ismarriedto->equalRange_2(key,READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_1_Ihaschild->equalRange_3(key,READ_OP_CONTEXT(rel_1_Ihaschild_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(105));
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
ret.push_back(env1[1]);
err.push_back(false);
ret.push_back((args)[0]);
err.push_back(false);
ret.push_back(env2[1]);
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
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(78),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(78));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
if(!rel_3_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt)).empty()) {
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
if(!(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(78),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_ismarriedto->equalRange_3(key,READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(78));
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
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(104),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(104));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
if(!rel_3_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Ihaschild_op_ctxt,rel_1_Ihaschild->createContext());
if(!rel_1_Ihaschild->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Ihaschild_op_ctxt)).empty()) {
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
if(!(rel_1_Ihaschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(104),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Ihaschild_op_ctxt,rel_1_Ihaschild->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_ismarriedto->equalRange_2(key,READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_1_Ihaschild->equalRange_3(key,READ_OP_CONTEXT(rel_1_Ihaschild_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(104));
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
ret.push_back(env1[0]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
err.push_back(false);
ret.push_back(env1[1]);
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
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(130),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(130));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
if(!rel_3_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
if(!rel_4_haschild->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_haschild_op_ctxt)).empty()) {
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
if(!(rel_4_haschild->empty()) && !(rel_3_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(130),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_ismarriedto_op_ctxt,rel_3_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_4_haschild_op_ctxt,rel_4_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_ismarriedto->equalRange_1(key,READ_OP_CONTEXT(rel_3_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_4_haschild->equalRange_3(key,READ_OP_CONTEXT(rel_4_haschild_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(130));
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
souffle::CmdOptions opt(R"(sol_haschild.dl)",
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
