
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
	R"_(produced,v0,v1)_",
	R"_(actedin(v0,v1) :- 
   Rule(268),
   produced(v0,v1).)_",
	R"_(created,v1,v2)_",
	R"_(Iactedin,v0,v2)_",
	R"_(actedin(v0,v1) :- 
   Rule(409),
   created(v1,v2),
   Iactedin(v0,v2).)_",
	R"_(produced,v2,v1)_",
	R"_(Iactedin,v2,v0)_",
	R"_(actedin(v0,v1) :- 
   Rule(468),
   produced(v2,v1),
   Iactedin(v2,v0).)_",
	R"_(directed,v2,v1)_",
	R"_(actedin(v0,v1) :- 
   Rule(516),
   directed(v2,v1),
   Iactedin(v2,v0).)_",
	R"_(Iactedin,v1,v2)_",
	R"_(actedin(v0,v1) :- 
   Rule(550),
   Iactedin(v0,v2),
   Iactedin(v1,v2).)_",
	R"_(ismarriedto,v1,v2)_",
	R"_(actedin(v0,v1) :- 
   Rule(331),
   ismarriedto(v1,v2),
   Iactedin(v2,v0).)_",
	R"_(ismarriedto,v2,v0)_",
	R"_(actedin,v1,v2)_",
	R"_(actedin(v0,v1) :- 
   Rule(356),
   ismarriedto(v2,v0),
   actedin(v1,v2).)_",
	R"_(created,v2,v1)_",
	R"_(actedin,v0,v2)_",
	R"_(actedin(v0,v1) :- 
   Rule(426),
   created(v2,v1),
   actedin(v0,v2).)_",
	R"_(Iactedin,v2,v1)_",
	R"_(actedin(v0,v1) :- 
   Rule(333),
   ismarriedto(v2,v0),
   Iactedin(v2,v1).)_",
	R"_(created,v0,v2)_",
	R"_(actedin(v0,v1) :- 
   Rule(430),
   created(v0,v2),
   actedin(v1,v2).)_",
	R"_(produced,v0,v2)_",
	R"_(actedin(v0,v1) :- 
   Rule(490),
   produced(v0,v2),
   actedin(v1,v2).)_",
	R"_(directed,v0,v1)_",
	R"_(actedin(v0,v1) :- 
   Rule(270),
   directed(v0,v1).)_",
	R"_(ismarriedto,v2,v1)_",
	R"_(actedin(v0,v1) :- 
   Rule(336),
   ismarriedto(v2,v1),
   Iactedin(v2,v0).)_",
	R"_(actedin(v0,v1) :- 
   Rule(570),
   Iactedin(v2,v1),
   actedin(v0,v2).)_",
	R"_(ismarriedto,v0,v2)_",
	R"_(actedin(v0,v1) :- 
   Rule(358),
   ismarriedto(v0,v2),
   actedin(v1,v2).)_",
	R"_(created,v0,v1)_",
	R"_(actedin(v0,v1) :- 
   Rule(266),
   created(v0,v1).)_",
	R"_(actedin(v0,v1) :- 
   Rule(408),
   created(v2,v1),
   Iactedin(v2,v0).)_",
	R"_(directed,v0,v2)_",
	R"_(actedin(v0,v1) :- 
   Rule(538),
   directed(v0,v2),
   actedin(v1,v2).)_",
};// -- Table: Iactedin
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_1_Iactedin = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<0,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_1_Iactedin;
// -- Table: Rule
std::unique_ptr<t_btree_3__0_1_2__1__7> rel_2_Rule = std::make_unique<t_btree_3__0_1_2__1__7>();
souffle::RelationWrapper<1,t_btree_3__0_1_2__1__7,Tuple<RamDomain,3>,3> wrapper_rel_2_Rule;
// -- Table: created
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_3_created = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<2,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_3_created;
// -- Table: directed
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_4_directed = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<3,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_4_directed;
// -- Table: ismarriedto
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_5_ismarriedto = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<4,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_5_ismarriedto;
// -- Table: produced
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_6_produced = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<5,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_6_produced;
// -- Table: actedin
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_7_actedin = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<6,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_7_actedin;
// -- Table: @delta_actedin
std::unique_ptr<t_btree_4__1_0_2_3__2__15> rel_8_delta_actedin = std::make_unique<t_btree_4__1_0_2_3__2__15>();
// -- Table: @new_actedin
std::unique_ptr<t_btree_4__1_0_2_3__2__15> rel_9_new_actedin = std::make_unique<t_btree_4__1_0_2_3__2__15>();
// -- Table: actedin.@info.1
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_10_actedin_info_1 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<7,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_10_actedin_info_1;
// -- Table: actedin.@info.10
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_11_actedin_info_10 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<8,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_11_actedin_info_10;
// -- Table: actedin.@info.11
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_12_actedin_info_11 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<9,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_12_actedin_info_11;
// -- Table: actedin.@info.12
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_13_actedin_info_12 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<10,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_13_actedin_info_12;
// -- Table: actedin.@info.13
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_14_actedin_info_13 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<11,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_14_actedin_info_13;
// -- Table: actedin.@info.14
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_15_actedin_info_14 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<12,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_15_actedin_info_14;
// -- Table: actedin.@info.15
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_16_actedin_info_15 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<13,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_16_actedin_info_15;
// -- Table: actedin.@info.16
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_17_actedin_info_16 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<14,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_17_actedin_info_16;
// -- Table: actedin.@info.17
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_18_actedin_info_17 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<15,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_18_actedin_info_17;
// -- Table: actedin.@info.18
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_19_actedin_info_18 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<16,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_19_actedin_info_18;
// -- Table: actedin.@info.2
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_20_actedin_info_2 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<17,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_20_actedin_info_2;
// -- Table: actedin.@info.3
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_21_actedin_info_3 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<18,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_21_actedin_info_3;
// -- Table: actedin.@info.4
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_22_actedin_info_4 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<19,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_22_actedin_info_4;
// -- Table: actedin.@info.5
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_23_actedin_info_5 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<20,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_23_actedin_info_5;
// -- Table: actedin.@info.6
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_24_actedin_info_6 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<21,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_24_actedin_info_6;
// -- Table: actedin.@info.7
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_25_actedin_info_7 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<22,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_25_actedin_info_7;
// -- Table: actedin.@info.8
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_26_actedin_info_8 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<23,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_26_actedin_info_8;
// -- Table: actedin.@info.9
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_27_actedin_info_9 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<24,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_27_actedin_info_9;
// -- Table: inv_0
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_28_inv_0 = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<25,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4> wrapper_rel_28_inv_0;
public:
Sf_program_small() : 
wrapper_rel_1_Iactedin(*rel_1_Iactedin,symTable,"Iactedin",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_2_Rule(*rel_2_Rule,symTable,"Rule",std::array<const char *,3>{{"i:number","i:number","i:number"}},std::array<const char *,3>{{"n","@rule_number","@level_number"}}),

wrapper_rel_3_created(*rel_3_created,symTable,"created",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_4_directed(*rel_4_directed,symTable,"directed",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_5_ismarriedto(*rel_5_ismarriedto,symTable,"ismarriedto",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_6_produced(*rel_6_produced,symTable,"produced",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_7_actedin(*rel_7_actedin,symTable,"actedin",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_10_actedin_info_1(*rel_10_actedin_info_1,symTable,"actedin.@info.1",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_11_actedin_info_10(*rel_11_actedin_info_10,symTable,"actedin.@info.10",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_12_actedin_info_11(*rel_12_actedin_info_11,symTable,"actedin.@info.11",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_13_actedin_info_12(*rel_13_actedin_info_12,symTable,"actedin.@info.12",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_14_actedin_info_13(*rel_14_actedin_info_13,symTable,"actedin.@info.13",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_15_actedin_info_14(*rel_15_actedin_info_14,symTable,"actedin.@info.14",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_16_actedin_info_15(*rel_16_actedin_info_15,symTable,"actedin.@info.15",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_17_actedin_info_16(*rel_17_actedin_info_16,symTable,"actedin.@info.16",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_18_actedin_info_17(*rel_18_actedin_info_17,symTable,"actedin.@info.17",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_19_actedin_info_18(*rel_19_actedin_info_18,symTable,"actedin.@info.18",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_20_actedin_info_2(*rel_20_actedin_info_2,symTable,"actedin.@info.2",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_21_actedin_info_3(*rel_21_actedin_info_3,symTable,"actedin.@info.3",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_22_actedin_info_4(*rel_22_actedin_info_4,symTable,"actedin.@info.4",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_23_actedin_info_5(*rel_23_actedin_info_5,symTable,"actedin.@info.5",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_24_actedin_info_6(*rel_24_actedin_info_6,symTable,"actedin.@info.6",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_25_actedin_info_7(*rel_25_actedin_info_7,symTable,"actedin.@info.7",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_26_actedin_info_8(*rel_26_actedin_info_8,symTable,"actedin.@info.8",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_27_actedin_info_9(*rel_27_actedin_info_9,symTable,"actedin.@info.9",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_28_inv_0(*rel_28_inv_0,symTable,"inv_0",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}){
addRelation("Iactedin",&wrapper_rel_1_Iactedin,true,false);
addRelation("Rule",&wrapper_rel_2_Rule,true,false);
addRelation("created",&wrapper_rel_3_created,true,false);
addRelation("directed",&wrapper_rel_4_directed,true,false);
addRelation("ismarriedto",&wrapper_rel_5_ismarriedto,true,false);
addRelation("produced",&wrapper_rel_6_produced,true,false);
addRelation("actedin",&wrapper_rel_7_actedin,false,true);
addRelation("actedin.@info.1",&wrapper_rel_10_actedin_info_1,false,false);
addRelation("actedin.@info.10",&wrapper_rel_11_actedin_info_10,false,false);
addRelation("actedin.@info.11",&wrapper_rel_12_actedin_info_11,false,false);
addRelation("actedin.@info.12",&wrapper_rel_13_actedin_info_12,false,false);
addRelation("actedin.@info.13",&wrapper_rel_14_actedin_info_13,false,false);
addRelation("actedin.@info.14",&wrapper_rel_15_actedin_info_14,false,false);
addRelation("actedin.@info.15",&wrapper_rel_16_actedin_info_15,false,false);
addRelation("actedin.@info.16",&wrapper_rel_17_actedin_info_16,false,false);
addRelation("actedin.@info.17",&wrapper_rel_18_actedin_info_17,false,false);
addRelation("actedin.@info.18",&wrapper_rel_19_actedin_info_18,false,false);
addRelation("actedin.@info.2",&wrapper_rel_20_actedin_info_2,false,false);
addRelation("actedin.@info.3",&wrapper_rel_21_actedin_info_3,false,false);
addRelation("actedin.@info.4",&wrapper_rel_22_actedin_info_4,false,false);
addRelation("actedin.@info.5",&wrapper_rel_23_actedin_info_5,false,false);
addRelation("actedin.@info.6",&wrapper_rel_24_actedin_info_6,false,false);
addRelation("actedin.@info.7",&wrapper_rel_25_actedin_info_7,false,false);
addRelation("actedin.@info.8",&wrapper_rel_26_actedin_info_8,false,false);
addRelation("actedin.@info.9",&wrapper_rel_27_actedin_info_9,false,false);
addRelation("inv_0",&wrapper_rel_28_inv_0,false,true);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Iactedin.facts"},{"name","Iactedin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_Iactedin);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./created.facts"},{"name","created"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_created);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./ismarriedto.facts"},{"name","ismarriedto"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_5_ismarriedto);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./produced.facts"},{"name","produced"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_6_produced);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,1,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(268,_,@level_num_0),
   produced(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [27:1-27:48])_");
if(!(rel_6_produced->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(268),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_6_produced_op_ctxt,rel_6_produced->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_6_produced) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(1)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_7_actedin->insert(tuple,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,2,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(409,_,@level_num_0),
   created(v1,v2,_,@level_num_1),
   Iactedin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [28:1-28:65])_");
if(!(rel_1_Iactedin->empty()) && !(rel_3_created->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(409),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_created) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_1_Iactedin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(2)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_actedin->insert(tuple,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,3,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(468,_,@level_num_0),
   produced(v2,v1,_,@level_num_1),
   Iactedin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [29:1-29:66])_");
if(!(rel_1_Iactedin->empty()) && !(rel_6_produced->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(468),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_6_produced_op_ctxt,rel_6_produced->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_6_produced) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Iactedin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(3)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_actedin->insert(tuple,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,4,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(516,_,@level_num_0),
   directed(v2,v1,_,@level_num_1),
   Iactedin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [30:1-30:66])_");
if(!(rel_1_Iactedin->empty()) && !(rel_4_directed->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(516),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_4_directed_op_ctxt,rel_4_directed->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_directed) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Iactedin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(4)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_actedin->insert(tuple,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,5,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(550,_,@level_num_0),
   Iactedin(v0,v2,_,@level_num_1),
   Iactedin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [31:1-31:66])_");
if(!(rel_1_Iactedin->empty()) && !(rel_1_Iactedin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(550),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iactedin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_1_Iactedin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(5)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_actedin->insert(tuple,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,6,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(331,_,@level_num_0),
   ismarriedto(v1,v2,_,@level_num_1),
   Iactedin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [32:1-32:69])_");
if(!(rel_1_Iactedin->empty()) && !(rel_5_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(331),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_ismarriedto) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_1_Iactedin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(6)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_actedin->insert(tuple,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,9,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(333,_,@level_num_0),
   ismarriedto(v2,v0,_,@level_num_1),
   Iactedin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [35:1-35:69])_");
if(!(rel_1_Iactedin->empty()) && !(rel_5_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(333),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_ismarriedto) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Iactedin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(9)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_actedin->insert(tuple,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,12,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(270,_,@level_num_0),
   directed(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [38:1-38:48])_");
if(!(rel_4_directed->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(270),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_directed_op_ctxt,rel_4_directed->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_directed) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(12)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_7_actedin->insert(tuple,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,13,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(336,_,@level_num_0),
   ismarriedto(v2,v1,_,@level_num_1),
   Iactedin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [39:1-39:69])_");
if(!(rel_1_Iactedin->empty()) && !(rel_5_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(336),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_ismarriedto) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Iactedin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(13)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_actedin->insert(tuple,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,16,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(266,_,@level_num_0),
   created(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [42:1-42:47])_");
if(!(rel_3_created->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(266),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_created) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(16)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_7_actedin->insert(tuple,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,17,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(408,_,@level_num_0),
   created(v2,v1,_,@level_num_1),
   Iactedin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [43:1-43:65])_");
if(!(rel_1_Iactedin->empty()) && !(rel_3_created->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(408),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_created) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Iactedin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(17)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_actedin->insert(tuple,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
rel_8_delta_actedin->insertAll(*rel_7_actedin);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,7,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(356,_,@level_num_0),
   ismarriedto(v2,v0,_,@level_num_1),
   actedin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [33:1-33:68])_");
if(!(rel_8_delta_actedin->empty()) && !(rel_5_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(356),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_actedin_op_ctxt,rel_8_delta_actedin->createContext());
CREATE_OP_CONTEXT(rel_9_new_actedin_op_ctxt,rel_9_new_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_ismarriedto) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_8_delta_actedin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_actedin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(7)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_actedin->insert(tuple,READ_OP_CONTEXT(rel_9_new_actedin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,8,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(426,_,@level_num_0),
   created(v2,v1,_,@level_num_1),
   actedin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [34:1-34:64])_");
if(!(rel_8_delta_actedin->empty()) && !(rel_3_created->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(426),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_actedin_op_ctxt,rel_8_delta_actedin->createContext());
CREATE_OP_CONTEXT(rel_9_new_actedin_op_ctxt,rel_9_new_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_created) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_8_delta_actedin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_actedin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(8)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_actedin->insert(tuple,READ_OP_CONTEXT(rel_9_new_actedin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,10,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(430,_,@level_num_0),
   created(v0,v2,_,@level_num_1),
   actedin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [36:1-36:64])_");
if(!(rel_8_delta_actedin->empty()) && !(rel_3_created->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(430),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_actedin_op_ctxt,rel_8_delta_actedin->createContext());
CREATE_OP_CONTEXT(rel_9_new_actedin_op_ctxt,rel_9_new_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_created) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_8_delta_actedin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_actedin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(10)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_actedin->insert(tuple,READ_OP_CONTEXT(rel_9_new_actedin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,11,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(490,_,@level_num_0),
   produced(v0,v2,_,@level_num_1),
   actedin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [37:1-37:65])_");
if(!(rel_8_delta_actedin->empty()) && !(rel_6_produced->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(490),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_6_produced_op_ctxt,rel_6_produced->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_actedin_op_ctxt,rel_8_delta_actedin->createContext());
CREATE_OP_CONTEXT(rel_9_new_actedin_op_ctxt,rel_9_new_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_6_produced) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_8_delta_actedin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_actedin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(11)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_actedin->insert(tuple,READ_OP_CONTEXT(rel_9_new_actedin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,14,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(570,_,@level_num_0),
   Iactedin(v2,v1,_,@level_num_1),
   actedin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [40:1-40:65])_");
if(!(rel_8_delta_actedin->empty()) && !(rel_1_Iactedin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(570),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_actedin_op_ctxt,rel_8_delta_actedin->createContext());
CREATE_OP_CONTEXT(rel_9_new_actedin_op_ctxt,rel_9_new_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iactedin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_8_delta_actedin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_actedin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(14)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_actedin->insert(tuple,READ_OP_CONTEXT(rel_9_new_actedin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,15,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(358,_,@level_num_0),
   ismarriedto(v0,v2,_,@level_num_1),
   actedin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [41:1-41:68])_");
if(!(rel_8_delta_actedin->empty()) && !(rel_5_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(358),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_actedin_op_ctxt,rel_8_delta_actedin->createContext());
CREATE_OP_CONTEXT(rel_9_new_actedin_op_ctxt,rel_9_new_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_ismarriedto) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_8_delta_actedin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_actedin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(15)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_actedin->insert(tuple,READ_OP_CONTEXT(rel_9_new_actedin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(actedin(v0,v1,18,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(538,_,@level_num_0),
   directed(v0,v2,_,@level_num_1),
   actedin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/films/solution.dl [44:1-44:65])_");
if(!(rel_8_delta_actedin->empty()) && !(rel_4_directed->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(538),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_directed_op_ctxt,rel_4_directed->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_actedin_op_ctxt,rel_8_delta_actedin->createContext());
CREATE_OP_CONTEXT(rel_9_new_actedin_op_ctxt,rel_9_new_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_directed) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_8_delta_actedin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_actedin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(18)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_actedin->insert(tuple,READ_OP_CONTEXT(rel_9_new_actedin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
if(rel_9_new_actedin->empty()) break;
rel_7_actedin->insertAll(*rel_9_new_actedin);
std::swap(rel_8_delta_actedin, rel_9_new_actedin);
rel_9_new_actedin->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_8_delta_actedin->purge();
if (!isHintsProfilingEnabled()) rel_9_new_actedin->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./actedin.csv"},{"name","actedin"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_7_actedin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 6 */
/* BEGIN STRATUM 7 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.1(1,"v0,v1","Rule","produced,v0,v1","actedin(v0,v1) :- 
   Rule(268),
   produced(v0,v1).").
in file  [0:0-0:0])_");
rel_10_actedin_info_1->insert(RamDomain(1),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(3));
}();
/* END STRATUM 7 */
/* BEGIN STRATUM 8 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.10(10,"v0,v1","Rule","created,v0,v2","actedin,v1,v2","actedin(v0,v1) :- 
   Rule(430),
   created(v0,v2),
   actedin(v1,v2).").
in file  [0:0-0:0])_");
rel_11_actedin_info_10->insert(RamDomain(10),RamDomain(0),RamDomain(1),RamDomain(24),RamDomain(17),RamDomain(25));
}();
/* END STRATUM 8 */
/* BEGIN STRATUM 9 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.11(11,"v0,v1","Rule","produced,v0,v2","actedin,v1,v2","actedin(v0,v1) :- 
   Rule(490),
   produced(v0,v2),
   actedin(v1,v2).").
in file  [0:0-0:0])_");
rel_12_actedin_info_11->insert(RamDomain(11),RamDomain(0),RamDomain(1),RamDomain(26),RamDomain(17),RamDomain(27));
}();
/* END STRATUM 9 */
/* BEGIN STRATUM 10 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.12(12,"v0,v1","Rule","directed,v0,v1","actedin(v0,v1) :- 
   Rule(270),
   directed(v0,v1).").
in file  [0:0-0:0])_");
rel_13_actedin_info_12->insert(RamDomain(12),RamDomain(0),RamDomain(1),RamDomain(28),RamDomain(29));
}();
/* END STRATUM 10 */
/* BEGIN STRATUM 11 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.13(13,"v0,v1","Rule","ismarriedto,v2,v1","Iactedin,v2,v0","actedin(v0,v1) :- 
   Rule(336),
   ismarriedto(v2,v1),
   Iactedin(v2,v0).").
in file  [0:0-0:0])_");
rel_14_actedin_info_13->insert(RamDomain(13),RamDomain(0),RamDomain(1),RamDomain(30),RamDomain(8),RamDomain(31));
}();
/* END STRATUM 11 */
/* BEGIN STRATUM 12 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.14(14,"v0,v1","Rule","Iactedin,v2,v1","actedin,v0,v2","actedin(v0,v1) :- 
   Rule(570),
   Iactedin(v2,v1),
   actedin(v0,v2).").
in file  [0:0-0:0])_");
rel_15_actedin_info_14->insert(RamDomain(14),RamDomain(0),RamDomain(1),RamDomain(22),RamDomain(20),RamDomain(32));
}();
/* END STRATUM 12 */
/* BEGIN STRATUM 13 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.15(15,"v0,v1","Rule","ismarriedto,v0,v2","actedin,v1,v2","actedin(v0,v1) :- 
   Rule(358),
   ismarriedto(v0,v2),
   actedin(v1,v2).").
in file  [0:0-0:0])_");
rel_16_actedin_info_15->insert(RamDomain(15),RamDomain(0),RamDomain(1),RamDomain(33),RamDomain(17),RamDomain(34));
}();
/* END STRATUM 13 */
/* BEGIN STRATUM 14 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.16(16,"v0,v1","Rule","created,v0,v1","actedin(v0,v1) :- 
   Rule(266),
   created(v0,v1).").
in file  [0:0-0:0])_");
rel_17_actedin_info_16->insert(RamDomain(16),RamDomain(0),RamDomain(1),RamDomain(35),RamDomain(36));
}();
/* END STRATUM 14 */
/* BEGIN STRATUM 15 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.17(17,"v0,v1","Rule","created,v2,v1","Iactedin,v2,v0","actedin(v0,v1) :- 
   Rule(408),
   created(v2,v1),
   Iactedin(v2,v0).").
in file  [0:0-0:0])_");
rel_18_actedin_info_17->insert(RamDomain(17),RamDomain(0),RamDomain(1),RamDomain(19),RamDomain(8),RamDomain(37));
}();
/* END STRATUM 15 */
/* BEGIN STRATUM 16 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.18(18,"v0,v1","Rule","directed,v0,v2","actedin,v1,v2","actedin(v0,v1) :- 
   Rule(538),
   directed(v0,v2),
   actedin(v1,v2).").
in file  [0:0-0:0])_");
rel_19_actedin_info_18->insert(RamDomain(18),RamDomain(0),RamDomain(1),RamDomain(38),RamDomain(17),RamDomain(39));
}();
/* END STRATUM 16 */
/* BEGIN STRATUM 17 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.2(2,"v0,v1","Rule","created,v1,v2","Iactedin,v0,v2","actedin(v0,v1) :- 
   Rule(409),
   created(v1,v2),
   Iactedin(v0,v2).").
in file  [0:0-0:0])_");
rel_20_actedin_info_2->insert(RamDomain(2),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(5),RamDomain(6));
}();
/* END STRATUM 17 */
/* BEGIN STRATUM 18 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.3(3,"v0,v1","Rule","produced,v2,v1","Iactedin,v2,v0","actedin(v0,v1) :- 
   Rule(468),
   produced(v2,v1),
   Iactedin(v2,v0).").
in file  [0:0-0:0])_");
rel_21_actedin_info_3->insert(RamDomain(3),RamDomain(0),RamDomain(1),RamDomain(7),RamDomain(8),RamDomain(9));
}();
/* END STRATUM 18 */
/* BEGIN STRATUM 19 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.4(4,"v0,v1","Rule","directed,v2,v1","Iactedin,v2,v0","actedin(v0,v1) :- 
   Rule(516),
   directed(v2,v1),
   Iactedin(v2,v0).").
in file  [0:0-0:0])_");
rel_22_actedin_info_4->insert(RamDomain(4),RamDomain(0),RamDomain(1),RamDomain(10),RamDomain(8),RamDomain(11));
}();
/* END STRATUM 19 */
/* BEGIN STRATUM 20 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.5(5,"v0,v1","Rule","Iactedin,v0,v2","Iactedin,v1,v2","actedin(v0,v1) :- 
   Rule(550),
   Iactedin(v0,v2),
   Iactedin(v1,v2).").
in file  [0:0-0:0])_");
rel_23_actedin_info_5->insert(RamDomain(5),RamDomain(0),RamDomain(1),RamDomain(5),RamDomain(12),RamDomain(13));
}();
/* END STRATUM 20 */
/* BEGIN STRATUM 21 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.6(6,"v0,v1","Rule","ismarriedto,v1,v2","Iactedin,v2,v0","actedin(v0,v1) :- 
   Rule(331),
   ismarriedto(v1,v2),
   Iactedin(v2,v0).").
in file  [0:0-0:0])_");
rel_24_actedin_info_6->insert(RamDomain(6),RamDomain(0),RamDomain(1),RamDomain(14),RamDomain(8),RamDomain(15));
}();
/* END STRATUM 21 */
/* BEGIN STRATUM 22 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.7(7,"v0,v1","Rule","ismarriedto,v2,v0","actedin,v1,v2","actedin(v0,v1) :- 
   Rule(356),
   ismarriedto(v2,v0),
   actedin(v1,v2).").
in file  [0:0-0:0])_");
rel_25_actedin_info_7->insert(RamDomain(7),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(17),RamDomain(18));
}();
/* END STRATUM 22 */
/* BEGIN STRATUM 23 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.8(8,"v0,v1","Rule","created,v2,v1","actedin,v0,v2","actedin(v0,v1) :- 
   Rule(426),
   created(v2,v1),
   actedin(v0,v2).").
in file  [0:0-0:0])_");
rel_26_actedin_info_8->insert(RamDomain(8),RamDomain(0),RamDomain(1),RamDomain(19),RamDomain(20),RamDomain(21));
}();
/* END STRATUM 23 */
/* BEGIN STRATUM 24 */
[&]() {
SignalHandler::instance()->setMsg(R"_(actedin.@info.9(9,"v0,v1","Rule","ismarriedto,v2,v0","Iactedin,v2,v1","actedin(v0,v1) :- 
   Rule(333),
   ismarriedto(v2,v0),
   Iactedin(v2,v1).").
in file  [0:0-0:0])_");
rel_27_actedin_info_9->insert(RamDomain(9),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(22),RamDomain(23));
}();
/* END STRATUM 24 */
/* BEGIN STRATUM 25 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./inv_0.csv"},{"name","inv_0"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_28_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 25 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_Iactedin:\n";
rel_1_Iactedin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_Rule:\n";
rel_2_Rule->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_created:\n";
rel_3_created->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_directed:\n";
rel_4_directed->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_ismarriedto:\n";
rel_5_ismarriedto->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_produced:\n";
rel_6_produced->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_actedin:\n";
rel_7_actedin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_delta_actedin:\n";
rel_8_delta_actedin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_new_actedin:\n";
rel_9_new_actedin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_actedin_info_1:\n";
rel_10_actedin_info_1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_actedin_info_10:\n";
rel_11_actedin_info_10->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_actedin_info_11:\n";
rel_12_actedin_info_11->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_13_actedin_info_12:\n";
rel_13_actedin_info_12->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_14_actedin_info_13:\n";
rel_14_actedin_info_13->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_15_actedin_info_14:\n";
rel_15_actedin_info_14->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_16_actedin_info_15:\n";
rel_16_actedin_info_15->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_17_actedin_info_16:\n";
rel_17_actedin_info_16->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_18_actedin_info_17:\n";
rel_18_actedin_info_17->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_19_actedin_info_18:\n";
rel_19_actedin_info_18->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_20_actedin_info_2:\n";
rel_20_actedin_info_2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_21_actedin_info_3:\n";
rel_21_actedin_info_3->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_22_actedin_info_4:\n";
rel_22_actedin_info_4->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_23_actedin_info_5:\n";
rel_23_actedin_info_5->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_24_actedin_info_6:\n";
rel_24_actedin_info_6->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_25_actedin_info_7:\n";
rel_25_actedin_info_7->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_26_actedin_info_8:\n";
rel_26_actedin_info_8->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_27_actedin_info_9:\n";
rel_27_actedin_info_9->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_28_inv_0:\n";
rel_28_inv_0->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./actedin.csv"},{"name","actedin"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_7_actedin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./inv_0.csv"},{"name","inv_0"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_28_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Iactedin.facts"},{"name","Iactedin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_Iactedin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Rule.facts"},{"name","Rule"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->readAll(*rel_2_Rule);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./created.facts"},{"name","created"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_created);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./directed.facts"},{"name","directed"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_4_directed);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./ismarriedto.facts"},{"name","ismarriedto"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_5_ismarriedto);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./produced.facts"},{"name","produced"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_6_produced);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_Iactedin");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_1_Iactedin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_Rule");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->writeAll(*rel_2_Rule);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_created");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_3_created);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_4_directed");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_directed);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_5_ismarriedto");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_5_ismarriedto);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_6_produced");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_6_produced);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_7_actedin");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_7_actedin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_28_inv_0");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_28_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
SymbolTable& getSymbolTable() override {
return symTable;
}
void executeSubroutine(std::string name, const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) override {
if (name == "actedin_10_negation_subproof") {
subproof_0(args, ret, err);
}
if (name == "actedin_10_subproof") {
subproof_1(args, ret, err);
}
if (name == "actedin_11_negation_subproof") {
subproof_2(args, ret, err);
}
if (name == "actedin_11_subproof") {
subproof_3(args, ret, err);
}
if (name == "actedin_12_negation_subproof") {
subproof_4(args, ret, err);
}
if (name == "actedin_12_subproof") {
subproof_5(args, ret, err);
}
if (name == "actedin_13_negation_subproof") {
subproof_6(args, ret, err);
}
if (name == "actedin_13_subproof") {
subproof_7(args, ret, err);
}
if (name == "actedin_14_negation_subproof") {
subproof_8(args, ret, err);
}
if (name == "actedin_14_subproof") {
subproof_9(args, ret, err);
}
if (name == "actedin_15_negation_subproof") {
subproof_10(args, ret, err);
}
if (name == "actedin_15_subproof") {
subproof_11(args, ret, err);
}
if (name == "actedin_16_negation_subproof") {
subproof_12(args, ret, err);
}
if (name == "actedin_16_subproof") {
subproof_13(args, ret, err);
}
if (name == "actedin_17_negation_subproof") {
subproof_14(args, ret, err);
}
if (name == "actedin_17_subproof") {
subproof_15(args, ret, err);
}
if (name == "actedin_18_negation_subproof") {
subproof_16(args, ret, err);
}
if (name == "actedin_18_subproof") {
subproof_17(args, ret, err);
}
if (name == "actedin_1_negation_subproof") {
subproof_18(args, ret, err);
}
if (name == "actedin_1_subproof") {
subproof_19(args, ret, err);
}
if (name == "actedin_2_negation_subproof") {
subproof_20(args, ret, err);
}
if (name == "actedin_2_subproof") {
subproof_21(args, ret, err);
}
if (name == "actedin_3_negation_subproof") {
subproof_22(args, ret, err);
}
if (name == "actedin_3_subproof") {
subproof_23(args, ret, err);
}
if (name == "actedin_4_negation_subproof") {
subproof_24(args, ret, err);
}
if (name == "actedin_4_subproof") {
subproof_25(args, ret, err);
}
if (name == "actedin_5_negation_subproof") {
subproof_26(args, ret, err);
}
if (name == "actedin_5_subproof") {
subproof_27(args, ret, err);
}
if (name == "actedin_6_negation_subproof") {
subproof_28(args, ret, err);
}
if (name == "actedin_6_subproof") {
subproof_29(args, ret, err);
}
if (name == "actedin_7_negation_subproof") {
subproof_30(args, ret, err);
}
if (name == "actedin_7_subproof") {
subproof_31(args, ret, err);
}
if (name == "actedin_8_negation_subproof") {
subproof_32(args, ret, err);
}
if (name == "actedin_8_subproof") {
subproof_33(args, ret, err);
}
if (name == "actedin_9_negation_subproof") {
subproof_34(args, ret, err);
}
if (name == "actedin_9_subproof") {
subproof_35(args, ret, err);
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
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
if(!rel_3_created->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_created_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
if(!rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt)).empty()) {
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
if(!(rel_7_actedin->empty()) && !(rel_3_created->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(430),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_created->equalRange_1(key,READ_OP_CONTEXT(rel_3_created_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_7_actedin->equalRange_3(key,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
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
CREATE_OP_CONTEXT(rel_6_produced_op_ctxt,rel_6_produced->createContext());
if(!rel_6_produced->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_6_produced_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
if(!rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt)).empty()) {
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
if(!(rel_7_actedin->empty()) && !(rel_6_produced->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(490),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_6_produced_op_ctxt,rel_6_produced->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_6_produced->equalRange_1(key,READ_OP_CONTEXT(rel_6_produced_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_7_actedin->equalRange_3(key,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
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
void subproof_4(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(270),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(270));
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
void subproof_5(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_directed->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(270),0,0}});
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
ret.push_back(RamDomain(270));
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
void subproof_6(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
if(!rel_5_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_5_ismarriedto_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
if(!rel_1_Iactedin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt)).empty()) {
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
if(!(rel_1_Iactedin->empty()) && !(rel_5_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(336),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_5_ismarriedto->equalRange_2(key,READ_OP_CONTEXT(rel_5_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_1_Iactedin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
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
void subproof_8(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(570),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(570));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
if(!rel_1_Iactedin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
if(!rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(2));
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
();return;
}
void subproof_9(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_actedin->empty()) && !(rel_1_Iactedin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(570),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_1_Iactedin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_7_actedin->equalRange_3(key,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(570));
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
ret.push_back(env2[0]);
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
void subproof_10(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
if(!rel_5_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_5_ismarriedto_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
if(!rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt)).empty()) {
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
void subproof_11(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_actedin->empty()) && !(rel_5_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(358),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_5_ismarriedto->equalRange_1(key,READ_OP_CONTEXT(rel_5_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_7_actedin->equalRange_3(key,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
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
void subproof_12(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
if(!rel_3_created->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_created_op_ctxt)).empty()) {
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
if(!(rel_3_created->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(266),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_created->equalRange_3(key,READ_OP_CONTEXT(rel_3_created_op_ctxt));
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
void subproof_14(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
if(!rel_3_created->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_created_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
if(!rel_1_Iactedin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt)).empty()) {
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
void subproof_15(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iactedin->empty()) && !(rel_3_created->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(408),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_created->equalRange_2(key,READ_OP_CONTEXT(rel_3_created_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_1_Iactedin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
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
void subproof_16(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(538),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(538));
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
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
if(!rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt)).empty()) {
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
if(!(rel_7_actedin->empty()) && !(rel_4_directed->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(538),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_directed_op_ctxt,rel_4_directed->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_4_directed->equalRange_1(key,READ_OP_CONTEXT(rel_4_directed_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_7_actedin->equalRange_3(key,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(538));
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
void subproof_18(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_6_produced_op_ctxt,rel_6_produced->createContext());
if(!rel_6_produced->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_6_produced_op_ctxt)).empty()) {
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
void subproof_19(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_6_produced->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(268),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_6_produced_op_ctxt,rel_6_produced->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_6_produced->equalRange_3(key,READ_OP_CONTEXT(rel_6_produced_op_ctxt));
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
void subproof_20(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(409),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(409));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
if(!rel_3_created->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_created_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
if(!rel_1_Iactedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(2));
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
();return;
}
void subproof_21(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iactedin->empty()) && !(rel_3_created->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(409),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_created->equalRange_1(key,READ_OP_CONTEXT(rel_3_created_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[1],0,0}});
auto range = rel_1_Iactedin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(409));
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
ret.push_back(env2[0]);
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
void subproof_22(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_6_produced_op_ctxt,rel_6_produced->createContext());
if(!rel_6_produced->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_6_produced_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
if(!rel_1_Iactedin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt)).empty()) {
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
void subproof_23(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iactedin->empty()) && !(rel_6_produced->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(468),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_6_produced_op_ctxt,rel_6_produced->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_6_produced->equalRange_2(key,READ_OP_CONTEXT(rel_6_produced_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_1_Iactedin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
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
void subproof_24(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(516),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(516));
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
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
if(!rel_1_Iactedin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt)).empty()) {
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
void subproof_25(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iactedin->empty()) && !(rel_4_directed->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(516),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
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
auto range = rel_1_Iactedin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(516));
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
void subproof_26(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(550),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(550));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
if(!rel_1_Iactedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
if(!rel_1_Iactedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt)).empty()) {
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
void subproof_27(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iactedin->empty()) && !(rel_1_Iactedin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(550),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_1_Iactedin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_1_Iactedin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(550));
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
void subproof_28(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(331),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(331));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
if(!rel_5_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_5_ismarriedto_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
if(!rel_1_Iactedin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt)).empty()) {
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
void subproof_29(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iactedin->empty()) && !(rel_5_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(331),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_5_ismarriedto->equalRange_1(key,READ_OP_CONTEXT(rel_5_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_1_Iactedin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(331));
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
void subproof_30(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(356),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(356));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
if(!rel_5_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_ismarriedto_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
if(!rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt)).empty()) {
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
void subproof_31(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_actedin->empty()) && !(rel_5_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(356),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_5_ismarriedto->equalRange_2(key,READ_OP_CONTEXT(rel_5_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_7_actedin->equalRange_3(key,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(356));
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
void subproof_32(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(426),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(426));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
if(!rel_3_created->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_created_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
if(!rel_7_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_actedin_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(2));
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
();return;
}
void subproof_33(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_actedin->empty()) && !(rel_3_created->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(426),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
CREATE_OP_CONTEXT(rel_7_actedin_op_ctxt,rel_7_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_created->equalRange_2(key,READ_OP_CONTEXT(rel_3_created_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_7_actedin->equalRange_3(key,READ_OP_CONTEXT(rel_7_actedin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(426));
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
ret.push_back(env2[0]);
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
void subproof_34(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(333),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(333));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
if(!rel_5_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_ismarriedto_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
if(!rel_1_Iactedin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt)).empty()) {
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
void subproof_35(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iactedin->empty()) && !(rel_5_ismarriedto->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(333),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_1_Iactedin_op_ctxt,rel_1_Iactedin->createContext());
CREATE_OP_CONTEXT(rel_5_ismarriedto_op_ctxt,rel_5_ismarriedto->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_5_ismarriedto->equalRange_2(key,READ_OP_CONTEXT(rel_5_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_1_Iactedin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iactedin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(333));
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
souffle::CmdOptions opt(R"(solution.dl)",
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
