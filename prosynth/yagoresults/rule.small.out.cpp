
#include "souffle/CompiledSouffle.h"
#include <mutex>
#include "souffle/Explain.h"

extern "C" {
}

namespace souffle {
using namespace ram;
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

class Sf_rule_small : public SouffleProgram {
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
	R"_(wasbornin,v0,v2)_",
	R"_(livesin,v1,v2)_",
	R"_(livesin(v0,v1) :- 
   Rule(130),
   wasbornin(v0,v2),
   livesin(v1,v2).)_",
};// -- Table: Rule
std::unique_ptr<t_btree_3__0_1_2__1__7> rel_1_Rule = std::make_unique<t_btree_3__0_1_2__1__7>();
souffle::RelationWrapper<0,t_btree_3__0_1_2__1__7,Tuple<RamDomain,3>,3> wrapper_rel_1_Rule;
// -- Table: inv_0
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_2_inv_0 = std::make_unique<t_btree_4__0_1_2_3__15>();
souffle::RelationWrapper<1,t_btree_4__0_1_2_3__15,Tuple<RamDomain,4>,4> wrapper_rel_2_inv_0;
// -- Table: wasbornin
std::unique_ptr<t_btree_4__0_1_2_3__1__3__15> rel_3_wasbornin = std::make_unique<t_btree_4__0_1_2_3__1__3__15>();
souffle::RelationWrapper<2,t_btree_4__0_1_2_3__1__3__15,Tuple<RamDomain,4>,4> wrapper_rel_3_wasbornin;
// -- Table: livesin
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_4_livesin = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<3,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_4_livesin;
// -- Table: @delta_livesin
std::unique_ptr<t_btree_4__1_0_2_3__2__15> rel_5_delta_livesin = std::make_unique<t_btree_4__1_0_2_3__2__15>();
// -- Table: @new_livesin
std::unique_ptr<t_btree_4__1_0_2_3__2__15> rel_6_new_livesin = std::make_unique<t_btree_4__1_0_2_3__2__15>();
// -- Table: livesin.@info.1
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_7_livesin_info_1 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<4,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_7_livesin_info_1;
public:
Sf_rule_small() : 
wrapper_rel_1_Rule(*rel_1_Rule,symTable,"Rule",std::array<const char *,3>{{"i:number","i:number","i:number"}},std::array<const char *,3>{{"n","@rule_number","@level_number"}}),

wrapper_rel_2_inv_0(*rel_2_inv_0,symTable,"inv_0",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_3_wasbornin(*rel_3_wasbornin,symTable,"wasbornin",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_4_livesin(*rel_4_livesin,symTable,"livesin",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_7_livesin_info_1(*rel_7_livesin_info_1,symTable,"livesin.@info.1",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}){
addRelation("Rule",&wrapper_rel_1_Rule,true,false);
addRelation("inv_0",&wrapper_rel_2_inv_0,false,true);
addRelation("wasbornin",&wrapper_rel_3_wasbornin,true,false);
addRelation("livesin",&wrapper_rel_4_livesin,false,true);
addRelation("livesin.@info.1",&wrapper_rel_7_livesin_info_1,false,false);
}
~Sf_rule_small() {
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Rule.facts"},{"name","Rule"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_Rule);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 0 */
/* BEGIN STRATUM 1 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./inv_0.csv"},{"name","inv_0"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_2_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 1 */
/* BEGIN STRATUM 2 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./wasbornin.facts"},{"name","wasbornin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_wasbornin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
rel_5_delta_livesin->insertAll(*rel_4_livesin);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(livesin(v0,v1,1,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(130,_,@level_num_0),
   wasbornin(v0,v2,_,@level_num_1),
   livesin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/yagoresults/rule.dl [35:1-35:66])_");
if(!(rel_5_delta_livesin->empty()) && !(rel_3_wasbornin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(130),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_wasbornin_op_ctxt,rel_3_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_4_livesin_op_ctxt,rel_4_livesin->createContext());
CREATE_OP_CONTEXT(rel_5_delta_livesin_op_ctxt,rel_5_delta_livesin->createContext());
CREATE_OP_CONTEXT(rel_6_new_livesin_op_ctxt,rel_6_new_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_wasbornin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_5_delta_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_5_delta_livesin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_livesin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_4_livesin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(1)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_livesin->insert(tuple,READ_OP_CONTEXT(rel_6_new_livesin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
if(rel_6_new_livesin->empty()) break;
rel_4_livesin->insertAll(*rel_6_new_livesin);
std::swap(rel_5_delta_livesin, rel_6_new_livesin);
rel_6_new_livesin->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_5_delta_livesin->purge();
if (!isHintsProfilingEnabled()) rel_6_new_livesin->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./livesin.csv"},{"name","livesin"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_livesin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesin.@info.1(1,"v0,v1","Rule","wasbornin,v0,v2","livesin,v1,v2","livesin(v0,v1) :- 
   Rule(130),
   wasbornin(v0,v2),
   livesin(v1,v2).").
in file  [0:0-0:0])_");
rel_7_livesin_info_1->insert(RamDomain(1),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(3),RamDomain(4));
}();
/* END STRATUM 4 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_Rule:\n";
rel_1_Rule->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_inv_0:\n";
rel_2_inv_0->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_wasbornin:\n";
rel_3_wasbornin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_livesin:\n";
rel_4_livesin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_delta_livesin:\n";
rel_5_delta_livesin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_new_livesin:\n";
rel_6_new_livesin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_livesin_info_1:\n";
rel_7_livesin_info_1->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./inv_0.csv"},{"name","inv_0"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_2_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./livesin.csv"},{"name","livesin"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_livesin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Rule.facts"},{"name","Rule"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_Rule);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./wasbornin.facts"},{"name","wasbornin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_wasbornin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_Rule");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->writeAll(*rel_1_Rule);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_wasbornin");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_3_wasbornin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_inv_0");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_2_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_4_livesin");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_livesin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
SymbolTable& getSymbolTable() override {
return symTable;
}
void executeSubroutine(std::string name, const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) override {
if (name == "livesin_1_negation_subproof") {
subproof_0(args, ret, err);
}
if (name == "livesin_1_subproof") {
subproof_1(args, ret, err);
}
}
void subproof_0(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(130),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_wasbornin_op_ctxt,rel_3_wasbornin->createContext());
if(!rel_3_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_wasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_livesin_op_ctxt,rel_4_livesin->createContext());
if(!rel_4_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_livesin_op_ctxt)).empty()) {
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
if(!(rel_4_livesin->empty()) && !(rel_3_wasbornin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(130),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_wasbornin_op_ctxt,rel_3_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_4_livesin_op_ctxt,rel_4_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_3_wasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_4_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_4_livesin_op_ctxt));
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
SouffleProgram *newInstance_rule_small(){return new Sf_rule_small;}
SymbolTable *getST_rule_small(SouffleProgram *p){return &reinterpret_cast<Sf_rule_small*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_rule_small: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_rule_small();
};
public:
factory_Sf_rule_small() : ProgramFactory("rule_small"){}
};
static factory_Sf_rule_small __factory_Sf_rule_small_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(rule.dl)",
R"(.)",
R"(.)",
false,
R"()",
5000,
-1);
if (!opt.parse(argc,argv)) return 1;
souffle::Sf_rule_small obj;
#if defined(_OPENMP) 
obj.setNumThreads(opt.getNumJobs());

#endif
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
explain(obj, false);
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
