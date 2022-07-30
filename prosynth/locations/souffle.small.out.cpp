
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

class Sf_souffle_small : public SouffleProgram {
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
	R"_(livesin,v0,v1)_",
	R"_(inv_0(v0,v1) :- 
   Rule(0),
   livesin(v0,v1).)_",
	R"_(livesin,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(1),
   livesin(v1,v0).)_",
	R"_(inv_0,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(5),
   inv_0(v1,v0).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(6),
   livesin(v0,v1).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(7),
   livesin(v0,v1),
   livesin(v1,v0).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(8),
   livesin(v1,v0).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(9),
   livesin(v1,v0),
   livesin(v0,v1).)_",
	R"_(livesin,v2,v1)_",
	R"_(livesin,v0,v2)_",
	R"_(inv_0(v0,v1) :- 
   Rule(10),
   livesin(v2,v1),
   livesin(v0,v2).)_",
	R"_(livesin,v1,v2)_",
	R"_(livesin,v2,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(11),
   livesin(v1,v2),
   livesin(v2,v0).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(12),
   livesin(v2,v0),
   livesin(v1,v2).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(13),
   livesin(v2,v0),
   livesin(v2,v1).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(14),
   livesin(v0,v2),
   livesin(v1,v2).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(15),
   livesin(v0,v2),
   livesin(v2,v1).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(16),
   livesin(v2,v1),
   livesin(v2,v0).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(17),
   livesin(v1,v2),
   livesin(v0,v2).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(31),
   livesin(v0,v1),
   inv_0(v1,v0).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(32),
   livesin(v1,v0),
   inv_0(v1,v0).)_",
	R"_(inv_0,v0,v2)_",
	R"_(inv_0(v0,v1) :- 
   Rule(34),
   livesin(v2,v1),
   inv_0(v0,v2).)_",
	R"_(inv_0,v2,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(35),
   livesin(v1,v2),
   inv_0(v2,v0).)_",
	R"_(inv_0,v1,v2)_",
	R"_(inv_0(v0,v1) :- 
   Rule(36),
   livesin(v2,v0),
   inv_0(v1,v2).)_",
	R"_(inv_0,v2,v1)_",
	R"_(inv_0(v0,v1) :- 
   Rule(37),
   livesin(v2,v0),
   inv_0(v2,v1).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(38),
   livesin(v0,v2),
   inv_0(v1,v2).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(39),
   livesin(v0,v2),
   inv_0(v2,v1).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(40),
   livesin(v2,v1),
   inv_0(v2,v0).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(41),
   livesin(v1,v2),
   inv_0(v0,v2).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(68),
   inv_0(v1,v0).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(70),
   inv_0(v2,v1),
   inv_0(v0,v2).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(71),
   inv_0(v1,v2),
   inv_0(v2,v0).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(72),
   inv_0(v2,v0),
   inv_0(v1,v2).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(73),
   inv_0(v2,v0),
   inv_0(v2,v1).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(74),
   inv_0(v0,v2),
   inv_0(v1,v2).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(75),
   inv_0(v0,v2),
   inv_0(v2,v1).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(76),
   inv_0(v2,v1),
   inv_0(v2,v0).)_",
	R"_(inv_0(v0,v1) :- 
   Rule(77),
   inv_0(v1,v2),
   inv_0(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(78),
   livesin(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(79),
   livesin(v1,v0).)_",
	R"_(inv_0,v0,v1)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(82),
   inv_0(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(83),
   inv_0(v1,v0).)_",
	R"_(wasbornin,v1,v0)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(85),
   wasbornin(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(86),
   livesin(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(87),
   livesin(v0,v1),
   livesin(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(88),
   livesin(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(89),
   livesin(v1,v0),
   livesin(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(90),
   livesin(v2,v1),
   livesin(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(91),
   livesin(v1,v2),
   livesin(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(92),
   livesin(v2,v0),
   livesin(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(93),
   livesin(v2,v0),
   livesin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(94),
   livesin(v0,v2),
   livesin(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(95),
   livesin(v0,v2),
   livesin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(96),
   livesin(v2,v1),
   livesin(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(97),
   livesin(v1,v2),
   livesin(v0,v2).)_",
	R"_(Iwasbornin,v0,v2)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(102),
   livesin(v2,v1),
   Iwasbornin(v0,v2).)_",
	R"_(Iwasbornin,v2,v0)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(103),
   livesin(v1,v2),
   Iwasbornin(v2,v0).)_",
	R"_(Iwasbornin,v1,v2)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(104),
   livesin(v2,v0),
   Iwasbornin(v1,v2).)_",
	R"_(Iwasbornin,v2,v1)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(105),
   livesin(v2,v0),
   Iwasbornin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(106),
   livesin(v0,v2),
   Iwasbornin(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(107),
   livesin(v0,v2),
   Iwasbornin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(108),
   livesin(v2,v1),
   Iwasbornin(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(109),
   livesin(v1,v2),
   Iwasbornin(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(110),
   livesin(v0,v1),
   inv_0(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(111),
   livesin(v0,v1),
   inv_0(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(112),
   livesin(v1,v0),
   inv_0(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(113),
   livesin(v1,v0),
   inv_0(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(114),
   livesin(v2,v1),
   inv_0(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(115),
   livesin(v1,v2),
   inv_0(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(116),
   livesin(v2,v0),
   inv_0(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(117),
   livesin(v2,v0),
   inv_0(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(118),
   livesin(v0,v2),
   inv_0(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(119),
   livesin(v0,v2),
   inv_0(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(120),
   livesin(v2,v1),
   inv_0(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(121),
   livesin(v1,v2),
   inv_0(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(123),
   livesin(v0,v1),
   wasbornin(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(124),
   livesin(v1,v0),
   wasbornin(v1,v0).)_",
	R"_(wasbornin,v0,v2)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(126),
   livesin(v2,v1),
   wasbornin(v0,v2).)_",
	R"_(wasbornin,v2,v0)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(127),
   livesin(v1,v2),
   wasbornin(v2,v0).)_",
	R"_(wasbornin,v1,v2)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(128),
   livesin(v2,v0),
   wasbornin(v1,v2).)_",
	R"_(wasbornin,v2,v1)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(129),
   livesin(v2,v0),
   wasbornin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(130),
   livesin(v0,v2),
   wasbornin(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(131),
   livesin(v0,v2),
   wasbornin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(132),
   livesin(v2,v1),
   wasbornin(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(133),
   livesin(v1,v2),
   wasbornin(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(138),
   Iwasbornin(v2,v1),
   Iwasbornin(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(139),
   Iwasbornin(v1,v2),
   Iwasbornin(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(140),
   Iwasbornin(v2,v0),
   Iwasbornin(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(141),
   Iwasbornin(v2,v0),
   Iwasbornin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(142),
   Iwasbornin(v0,v2),
   Iwasbornin(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(143),
   Iwasbornin(v0,v2),
   Iwasbornin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(144),
   Iwasbornin(v2,v1),
   Iwasbornin(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(145),
   Iwasbornin(v1,v2),
   Iwasbornin(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(162),
   Iwasbornin(v2,v1),
   wasbornin(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(163),
   Iwasbornin(v1,v2),
   wasbornin(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(164),
   Iwasbornin(v2,v0),
   wasbornin(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(165),
   Iwasbornin(v2,v0),
   wasbornin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(166),
   Iwasbornin(v0,v2),
   wasbornin(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(167),
   Iwasbornin(v0,v2),
   wasbornin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(168),
   Iwasbornin(v2,v1),
   wasbornin(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(169),
   Iwasbornin(v1,v2),
   wasbornin(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(170),
   inv_0(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(171),
   inv_0(v0,v1),
   inv_0(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(172),
   inv_0(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(173),
   inv_0(v1,v0),
   inv_0(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(174),
   inv_0(v2,v1),
   inv_0(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(175),
   inv_0(v1,v2),
   inv_0(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(176),
   inv_0(v2,v0),
   inv_0(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(177),
   inv_0(v2,v0),
   inv_0(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(178),
   inv_0(v0,v2),
   inv_0(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(179),
   inv_0(v0,v2),
   inv_0(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(180),
   inv_0(v2,v1),
   inv_0(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(181),
   inv_0(v1,v2),
   inv_0(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(183),
   inv_0(v0,v1),
   wasbornin(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(184),
   inv_0(v1,v0),
   wasbornin(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(186),
   inv_0(v2,v1),
   wasbornin(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(187),
   inv_0(v1,v2),
   wasbornin(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(188),
   inv_0(v2,v0),
   wasbornin(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(189),
   inv_0(v2,v0),
   wasbornin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(190),
   inv_0(v0,v2),
   wasbornin(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(191),
   inv_0(v0,v2),
   wasbornin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(192),
   inv_0(v2,v1),
   wasbornin(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(193),
   inv_0(v1,v2),
   wasbornin(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(196),
   wasbornin(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(198),
   wasbornin(v2,v1),
   wasbornin(v0,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(199),
   wasbornin(v1,v2),
   wasbornin(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(200),
   wasbornin(v2,v0),
   wasbornin(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(201),
   wasbornin(v2,v0),
   wasbornin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(202),
   wasbornin(v0,v2),
   wasbornin(v1,v2).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(203),
   wasbornin(v0,v2),
   wasbornin(v2,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(204),
   wasbornin(v2,v1),
   wasbornin(v2,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(205),
   wasbornin(v1,v2),
   wasbornin(v0,v2).)_",
};// -- Table: Iwasbornin
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_1_Iwasbornin = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<0,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_1_Iwasbornin;
// -- Table: Rule
std::unique_ptr<t_btree_3__0_1_2__1__7> rel_2_Rule = std::make_unique<t_btree_3__0_1_2__1__7>();
souffle::RelationWrapper<1,t_btree_3__0_1_2__1__7,Tuple<RamDomain,3>,3> wrapper_rel_2_Rule;
// -- Table: livesin
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_3_livesin = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<2,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_3_livesin;
// -- Table: inv_0
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_4_inv_0 = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<3,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_4_inv_0;
// -- Table: @delta_inv_0
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_5_delta_inv_0 = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
// -- Table: @new_inv_0
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_6_new_inv_0 = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
// -- Table: wasbornin
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_7_wasbornin = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<4,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_7_wasbornin;
// -- Table: @delta_wasbornin
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_8_delta_wasbornin = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
// -- Table: @new_wasbornin
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_9_new_wasbornin = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
// -- Table: inv_0.@info.1
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_10_inv_0_info_1 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<5,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_10_inv_0_info_1;
// -- Table: inv_0.@info.10
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_11_inv_0_info_10 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<6,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_11_inv_0_info_10;
// -- Table: inv_0.@info.11
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_12_inv_0_info_11 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<7,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_12_inv_0_info_11;
// -- Table: inv_0.@info.12
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_13_inv_0_info_12 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<8,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_13_inv_0_info_12;
// -- Table: inv_0.@info.13
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_14_inv_0_info_13 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<9,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_14_inv_0_info_13;
// -- Table: inv_0.@info.14
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_15_inv_0_info_14 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<10,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_15_inv_0_info_14;
// -- Table: inv_0.@info.15
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_16_inv_0_info_15 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<11,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_16_inv_0_info_15;
// -- Table: inv_0.@info.16
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_17_inv_0_info_16 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<12,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_17_inv_0_info_16;
// -- Table: inv_0.@info.17
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_18_inv_0_info_17 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<13,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_18_inv_0_info_17;
// -- Table: inv_0.@info.18
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_19_inv_0_info_18 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<14,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_19_inv_0_info_18;
// -- Table: inv_0.@info.19
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_20_inv_0_info_19 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<15,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_20_inv_0_info_19;
// -- Table: inv_0.@info.2
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_21_inv_0_info_2 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<16,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_21_inv_0_info_2;
// -- Table: inv_0.@info.20
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_22_inv_0_info_20 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<17,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_22_inv_0_info_20;
// -- Table: inv_0.@info.21
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_23_inv_0_info_21 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<18,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_23_inv_0_info_21;
// -- Table: inv_0.@info.22
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_24_inv_0_info_22 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<19,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_24_inv_0_info_22;
// -- Table: inv_0.@info.23
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_25_inv_0_info_23 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<20,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_25_inv_0_info_23;
// -- Table: inv_0.@info.24
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_26_inv_0_info_24 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<21,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_26_inv_0_info_24;
// -- Table: inv_0.@info.25
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_27_inv_0_info_25 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<22,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_27_inv_0_info_25;
// -- Table: inv_0.@info.26
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_28_inv_0_info_26 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<23,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_28_inv_0_info_26;
// -- Table: inv_0.@info.27
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_29_inv_0_info_27 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<24,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_29_inv_0_info_27;
// -- Table: inv_0.@info.28
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_30_inv_0_info_28 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<25,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_30_inv_0_info_28;
// -- Table: inv_0.@info.29
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_31_inv_0_info_29 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<26,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_31_inv_0_info_29;
// -- Table: inv_0.@info.3
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_32_inv_0_info_3 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<27,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_32_inv_0_info_3;
// -- Table: inv_0.@info.30
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_33_inv_0_info_30 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<28,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_33_inv_0_info_30;
// -- Table: inv_0.@info.31
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_34_inv_0_info_31 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<29,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_34_inv_0_info_31;
// -- Table: inv_0.@info.32
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_35_inv_0_info_32 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<30,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_35_inv_0_info_32;
// -- Table: inv_0.@info.33
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_36_inv_0_info_33 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<31,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_36_inv_0_info_33;
// -- Table: inv_0.@info.34
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_37_inv_0_info_34 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<32,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_37_inv_0_info_34;
// -- Table: inv_0.@info.4
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_38_inv_0_info_4 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<33,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_38_inv_0_info_4;
// -- Table: inv_0.@info.5
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_39_inv_0_info_5 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<34,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_39_inv_0_info_5;
// -- Table: inv_0.@info.6
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_40_inv_0_info_6 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<35,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_40_inv_0_info_6;
// -- Table: inv_0.@info.7
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_41_inv_0_info_7 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<36,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_41_inv_0_info_7;
// -- Table: inv_0.@info.8
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_42_inv_0_info_8 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<37,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_42_inv_0_info_8;
// -- Table: inv_0.@info.9
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_43_inv_0_info_9 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<38,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_43_inv_0_info_9;
// -- Table: wasbornin.@info.1
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_44_wasbornin_info_1 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<39,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_44_wasbornin_info_1;
// -- Table: wasbornin.@info.10
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_45_wasbornin_info_10 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<40,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_45_wasbornin_info_10;
// -- Table: wasbornin.@info.11
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_46_wasbornin_info_11 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<41,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_46_wasbornin_info_11;
// -- Table: wasbornin.@info.12
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_47_wasbornin_info_12 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<42,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_47_wasbornin_info_12;
// -- Table: wasbornin.@info.13
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_48_wasbornin_info_13 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<43,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_48_wasbornin_info_13;
// -- Table: wasbornin.@info.14
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_49_wasbornin_info_14 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<44,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_49_wasbornin_info_14;
// -- Table: wasbornin.@info.15
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_50_wasbornin_info_15 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<45,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_50_wasbornin_info_15;
// -- Table: wasbornin.@info.16
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_51_wasbornin_info_16 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<46,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_51_wasbornin_info_16;
// -- Table: wasbornin.@info.17
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_52_wasbornin_info_17 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<47,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_52_wasbornin_info_17;
// -- Table: wasbornin.@info.18
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_53_wasbornin_info_18 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<48,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_53_wasbornin_info_18;
// -- Table: wasbornin.@info.19
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_54_wasbornin_info_19 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<49,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_54_wasbornin_info_19;
// -- Table: wasbornin.@info.2
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_55_wasbornin_info_2 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<50,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_55_wasbornin_info_2;
// -- Table: wasbornin.@info.20
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_56_wasbornin_info_20 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<51,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_56_wasbornin_info_20;
// -- Table: wasbornin.@info.21
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_57_wasbornin_info_21 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<52,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_57_wasbornin_info_21;
// -- Table: wasbornin.@info.22
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_58_wasbornin_info_22 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<53,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_58_wasbornin_info_22;
// -- Table: wasbornin.@info.23
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_59_wasbornin_info_23 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<54,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_59_wasbornin_info_23;
// -- Table: wasbornin.@info.24
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_60_wasbornin_info_24 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<55,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_60_wasbornin_info_24;
// -- Table: wasbornin.@info.25
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_61_wasbornin_info_25 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<56,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_61_wasbornin_info_25;
// -- Table: wasbornin.@info.26
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_62_wasbornin_info_26 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<57,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_62_wasbornin_info_26;
// -- Table: wasbornin.@info.27
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_63_wasbornin_info_27 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<58,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_63_wasbornin_info_27;
// -- Table: wasbornin.@info.28
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_64_wasbornin_info_28 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<59,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_64_wasbornin_info_28;
// -- Table: wasbornin.@info.29
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_65_wasbornin_info_29 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<60,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_65_wasbornin_info_29;
// -- Table: wasbornin.@info.3
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_66_wasbornin_info_3 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<61,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_66_wasbornin_info_3;
// -- Table: wasbornin.@info.30
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_67_wasbornin_info_30 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<62,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_67_wasbornin_info_30;
// -- Table: wasbornin.@info.31
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_68_wasbornin_info_31 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<63,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_68_wasbornin_info_31;
// -- Table: wasbornin.@info.32
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_69_wasbornin_info_32 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<64,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_69_wasbornin_info_32;
// -- Table: wasbornin.@info.33
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_70_wasbornin_info_33 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<65,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_70_wasbornin_info_33;
// -- Table: wasbornin.@info.34
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_71_wasbornin_info_34 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<66,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_71_wasbornin_info_34;
// -- Table: wasbornin.@info.35
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_72_wasbornin_info_35 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<67,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_72_wasbornin_info_35;
// -- Table: wasbornin.@info.36
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_73_wasbornin_info_36 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<68,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_73_wasbornin_info_36;
// -- Table: wasbornin.@info.37
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_74_wasbornin_info_37 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<69,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_74_wasbornin_info_37;
// -- Table: wasbornin.@info.38
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_75_wasbornin_info_38 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<70,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_75_wasbornin_info_38;
// -- Table: wasbornin.@info.39
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_76_wasbornin_info_39 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<71,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_76_wasbornin_info_39;
// -- Table: wasbornin.@info.4
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_77_wasbornin_info_4 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<72,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_77_wasbornin_info_4;
// -- Table: wasbornin.@info.40
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_78_wasbornin_info_40 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<73,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_78_wasbornin_info_40;
// -- Table: wasbornin.@info.41
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_79_wasbornin_info_41 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<74,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_79_wasbornin_info_41;
// -- Table: wasbornin.@info.42
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_80_wasbornin_info_42 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<75,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_80_wasbornin_info_42;
// -- Table: wasbornin.@info.43
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_81_wasbornin_info_43 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<76,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_81_wasbornin_info_43;
// -- Table: wasbornin.@info.44
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_82_wasbornin_info_44 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<77,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_82_wasbornin_info_44;
// -- Table: wasbornin.@info.45
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_83_wasbornin_info_45 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<78,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_83_wasbornin_info_45;
// -- Table: wasbornin.@info.46
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_84_wasbornin_info_46 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<79,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_84_wasbornin_info_46;
// -- Table: wasbornin.@info.47
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_85_wasbornin_info_47 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<80,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_85_wasbornin_info_47;
// -- Table: wasbornin.@info.48
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_86_wasbornin_info_48 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<81,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_86_wasbornin_info_48;
// -- Table: wasbornin.@info.49
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_87_wasbornin_info_49 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<82,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_87_wasbornin_info_49;
// -- Table: wasbornin.@info.5
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_88_wasbornin_info_5 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<83,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_88_wasbornin_info_5;
// -- Table: wasbornin.@info.50
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_89_wasbornin_info_50 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<84,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_89_wasbornin_info_50;
// -- Table: wasbornin.@info.51
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_90_wasbornin_info_51 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<85,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_90_wasbornin_info_51;
// -- Table: wasbornin.@info.52
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_91_wasbornin_info_52 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<86,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_91_wasbornin_info_52;
// -- Table: wasbornin.@info.53
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_92_wasbornin_info_53 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<87,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_92_wasbornin_info_53;
// -- Table: wasbornin.@info.54
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_93_wasbornin_info_54 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<88,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_93_wasbornin_info_54;
// -- Table: wasbornin.@info.55
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_94_wasbornin_info_55 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<89,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_94_wasbornin_info_55;
// -- Table: wasbornin.@info.56
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_95_wasbornin_info_56 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<90,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_95_wasbornin_info_56;
// -- Table: wasbornin.@info.57
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_96_wasbornin_info_57 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<91,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_96_wasbornin_info_57;
// -- Table: wasbornin.@info.58
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_97_wasbornin_info_58 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<92,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_97_wasbornin_info_58;
// -- Table: wasbornin.@info.59
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_98_wasbornin_info_59 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<93,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_98_wasbornin_info_59;
// -- Table: wasbornin.@info.6
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_99_wasbornin_info_6 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<94,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_99_wasbornin_info_6;
// -- Table: wasbornin.@info.60
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_100_wasbornin_info_60 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<95,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_100_wasbornin_info_60;
// -- Table: wasbornin.@info.61
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_101_wasbornin_info_61 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<96,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_101_wasbornin_info_61;
// -- Table: wasbornin.@info.62
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_102_wasbornin_info_62 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<97,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_102_wasbornin_info_62;
// -- Table: wasbornin.@info.63
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_103_wasbornin_info_63 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<98,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_103_wasbornin_info_63;
// -- Table: wasbornin.@info.64
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_104_wasbornin_info_64 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<99,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_104_wasbornin_info_64;
// -- Table: wasbornin.@info.65
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_105_wasbornin_info_65 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<100,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_105_wasbornin_info_65;
// -- Table: wasbornin.@info.66
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_106_wasbornin_info_66 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<101,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_106_wasbornin_info_66;
// -- Table: wasbornin.@info.67
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_107_wasbornin_info_67 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<102,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_107_wasbornin_info_67;
// -- Table: wasbornin.@info.68
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_108_wasbornin_info_68 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<103,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_108_wasbornin_info_68;
// -- Table: wasbornin.@info.69
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_109_wasbornin_info_69 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<104,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_109_wasbornin_info_69;
// -- Table: wasbornin.@info.7
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_110_wasbornin_info_7 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<105,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_110_wasbornin_info_7;
// -- Table: wasbornin.@info.70
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_111_wasbornin_info_70 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<106,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_111_wasbornin_info_70;
// -- Table: wasbornin.@info.71
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_112_wasbornin_info_71 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<107,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_112_wasbornin_info_71;
// -- Table: wasbornin.@info.72
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_113_wasbornin_info_72 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<108,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_113_wasbornin_info_72;
// -- Table: wasbornin.@info.73
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_114_wasbornin_info_73 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<109,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_114_wasbornin_info_73;
// -- Table: wasbornin.@info.74
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_115_wasbornin_info_74 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<110,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_115_wasbornin_info_74;
// -- Table: wasbornin.@info.75
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_116_wasbornin_info_75 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<111,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_116_wasbornin_info_75;
// -- Table: wasbornin.@info.76
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_117_wasbornin_info_76 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<112,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_117_wasbornin_info_76;
// -- Table: wasbornin.@info.77
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_118_wasbornin_info_77 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<113,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_118_wasbornin_info_77;
// -- Table: wasbornin.@info.78
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_119_wasbornin_info_78 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<114,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_119_wasbornin_info_78;
// -- Table: wasbornin.@info.79
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_120_wasbornin_info_79 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<115,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_120_wasbornin_info_79;
// -- Table: wasbornin.@info.8
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_121_wasbornin_info_8 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<116,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_121_wasbornin_info_8;
// -- Table: wasbornin.@info.80
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_122_wasbornin_info_80 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<117,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_122_wasbornin_info_80;
// -- Table: wasbornin.@info.81
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_123_wasbornin_info_81 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<118,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_123_wasbornin_info_81;
// -- Table: wasbornin.@info.82
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_124_wasbornin_info_82 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<119,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_124_wasbornin_info_82;
// -- Table: wasbornin.@info.83
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_125_wasbornin_info_83 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<120,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_125_wasbornin_info_83;
// -- Table: wasbornin.@info.84
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_126_wasbornin_info_84 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<121,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_126_wasbornin_info_84;
// -- Table: wasbornin.@info.85
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_127_wasbornin_info_85 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<122,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_127_wasbornin_info_85;
// -- Table: wasbornin.@info.86
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_128_wasbornin_info_86 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<123,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_128_wasbornin_info_86;
// -- Table: wasbornin.@info.87
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_129_wasbornin_info_87 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<124,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_129_wasbornin_info_87;
// -- Table: wasbornin.@info.88
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_130_wasbornin_info_88 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<125,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_130_wasbornin_info_88;
// -- Table: wasbornin.@info.89
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_131_wasbornin_info_89 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<126,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_131_wasbornin_info_89;
// -- Table: wasbornin.@info.9
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_132_wasbornin_info_9 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<127,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_132_wasbornin_info_9;
// -- Table: wasbornin.@info.90
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_133_wasbornin_info_90 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<128,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_133_wasbornin_info_90;
// -- Table: wasbornin.@info.91
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_134_wasbornin_info_91 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<129,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_134_wasbornin_info_91;
// -- Table: wasbornin.@info.92
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_135_wasbornin_info_92 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<130,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_135_wasbornin_info_92;
// -- Table: wasbornin.@info.93
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_136_wasbornin_info_93 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<131,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_136_wasbornin_info_93;
// -- Table: wasbornin.@info.94
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_137_wasbornin_info_94 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<132,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_137_wasbornin_info_94;
public:
Sf_souffle_small() : 
wrapper_rel_1_Iwasbornin(*rel_1_Iwasbornin,symTable,"Iwasbornin",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_2_Rule(*rel_2_Rule,symTable,"Rule",std::array<const char *,3>{{"i:number","i:number","i:number"}},std::array<const char *,3>{{"n","@rule_number","@level_number"}}),

wrapper_rel_3_livesin(*rel_3_livesin,symTable,"livesin",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_4_inv_0(*rel_4_inv_0,symTable,"inv_0",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_7_wasbornin(*rel_7_wasbornin,symTable,"wasbornin",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_10_inv_0_info_1(*rel_10_inv_0_info_1,symTable,"inv_0.@info.1",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_11_inv_0_info_10(*rel_11_inv_0_info_10,symTable,"inv_0.@info.10",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_12_inv_0_info_11(*rel_12_inv_0_info_11,symTable,"inv_0.@info.11",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_13_inv_0_info_12(*rel_13_inv_0_info_12,symTable,"inv_0.@info.12",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_14_inv_0_info_13(*rel_14_inv_0_info_13,symTable,"inv_0.@info.13",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_15_inv_0_info_14(*rel_15_inv_0_info_14,symTable,"inv_0.@info.14",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_16_inv_0_info_15(*rel_16_inv_0_info_15,symTable,"inv_0.@info.15",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_17_inv_0_info_16(*rel_17_inv_0_info_16,symTable,"inv_0.@info.16",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_18_inv_0_info_17(*rel_18_inv_0_info_17,symTable,"inv_0.@info.17",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_19_inv_0_info_18(*rel_19_inv_0_info_18,symTable,"inv_0.@info.18",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_20_inv_0_info_19(*rel_20_inv_0_info_19,symTable,"inv_0.@info.19",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_21_inv_0_info_2(*rel_21_inv_0_info_2,symTable,"inv_0.@info.2",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_22_inv_0_info_20(*rel_22_inv_0_info_20,symTable,"inv_0.@info.20",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_23_inv_0_info_21(*rel_23_inv_0_info_21,symTable,"inv_0.@info.21",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_24_inv_0_info_22(*rel_24_inv_0_info_22,symTable,"inv_0.@info.22",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_25_inv_0_info_23(*rel_25_inv_0_info_23,symTable,"inv_0.@info.23",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_26_inv_0_info_24(*rel_26_inv_0_info_24,symTable,"inv_0.@info.24",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_27_inv_0_info_25(*rel_27_inv_0_info_25,symTable,"inv_0.@info.25",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_28_inv_0_info_26(*rel_28_inv_0_info_26,symTable,"inv_0.@info.26",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_29_inv_0_info_27(*rel_29_inv_0_info_27,symTable,"inv_0.@info.27",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_30_inv_0_info_28(*rel_30_inv_0_info_28,symTable,"inv_0.@info.28",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_31_inv_0_info_29(*rel_31_inv_0_info_29,symTable,"inv_0.@info.29",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_32_inv_0_info_3(*rel_32_inv_0_info_3,symTable,"inv_0.@info.3",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_33_inv_0_info_30(*rel_33_inv_0_info_30,symTable,"inv_0.@info.30",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_34_inv_0_info_31(*rel_34_inv_0_info_31,symTable,"inv_0.@info.31",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_35_inv_0_info_32(*rel_35_inv_0_info_32,symTable,"inv_0.@info.32",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_36_inv_0_info_33(*rel_36_inv_0_info_33,symTable,"inv_0.@info.33",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_37_inv_0_info_34(*rel_37_inv_0_info_34,symTable,"inv_0.@info.34",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_38_inv_0_info_4(*rel_38_inv_0_info_4,symTable,"inv_0.@info.4",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_39_inv_0_info_5(*rel_39_inv_0_info_5,symTable,"inv_0.@info.5",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_40_inv_0_info_6(*rel_40_inv_0_info_6,symTable,"inv_0.@info.6",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_41_inv_0_info_7(*rel_41_inv_0_info_7,symTable,"inv_0.@info.7",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_42_inv_0_info_8(*rel_42_inv_0_info_8,symTable,"inv_0.@info.8",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_43_inv_0_info_9(*rel_43_inv_0_info_9,symTable,"inv_0.@info.9",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_44_wasbornin_info_1(*rel_44_wasbornin_info_1,symTable,"wasbornin.@info.1",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_45_wasbornin_info_10(*rel_45_wasbornin_info_10,symTable,"wasbornin.@info.10",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_46_wasbornin_info_11(*rel_46_wasbornin_info_11,symTable,"wasbornin.@info.11",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_47_wasbornin_info_12(*rel_47_wasbornin_info_12,symTable,"wasbornin.@info.12",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_48_wasbornin_info_13(*rel_48_wasbornin_info_13,symTable,"wasbornin.@info.13",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_49_wasbornin_info_14(*rel_49_wasbornin_info_14,symTable,"wasbornin.@info.14",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_50_wasbornin_info_15(*rel_50_wasbornin_info_15,symTable,"wasbornin.@info.15",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_51_wasbornin_info_16(*rel_51_wasbornin_info_16,symTable,"wasbornin.@info.16",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_52_wasbornin_info_17(*rel_52_wasbornin_info_17,symTable,"wasbornin.@info.17",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_53_wasbornin_info_18(*rel_53_wasbornin_info_18,symTable,"wasbornin.@info.18",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_54_wasbornin_info_19(*rel_54_wasbornin_info_19,symTable,"wasbornin.@info.19",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_55_wasbornin_info_2(*rel_55_wasbornin_info_2,symTable,"wasbornin.@info.2",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_56_wasbornin_info_20(*rel_56_wasbornin_info_20,symTable,"wasbornin.@info.20",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_57_wasbornin_info_21(*rel_57_wasbornin_info_21,symTable,"wasbornin.@info.21",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_58_wasbornin_info_22(*rel_58_wasbornin_info_22,symTable,"wasbornin.@info.22",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_59_wasbornin_info_23(*rel_59_wasbornin_info_23,symTable,"wasbornin.@info.23",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_60_wasbornin_info_24(*rel_60_wasbornin_info_24,symTable,"wasbornin.@info.24",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_61_wasbornin_info_25(*rel_61_wasbornin_info_25,symTable,"wasbornin.@info.25",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_62_wasbornin_info_26(*rel_62_wasbornin_info_26,symTable,"wasbornin.@info.26",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_63_wasbornin_info_27(*rel_63_wasbornin_info_27,symTable,"wasbornin.@info.27",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_64_wasbornin_info_28(*rel_64_wasbornin_info_28,symTable,"wasbornin.@info.28",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_65_wasbornin_info_29(*rel_65_wasbornin_info_29,symTable,"wasbornin.@info.29",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_66_wasbornin_info_3(*rel_66_wasbornin_info_3,symTable,"wasbornin.@info.3",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_67_wasbornin_info_30(*rel_67_wasbornin_info_30,symTable,"wasbornin.@info.30",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_68_wasbornin_info_31(*rel_68_wasbornin_info_31,symTable,"wasbornin.@info.31",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_69_wasbornin_info_32(*rel_69_wasbornin_info_32,symTable,"wasbornin.@info.32",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_70_wasbornin_info_33(*rel_70_wasbornin_info_33,symTable,"wasbornin.@info.33",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_71_wasbornin_info_34(*rel_71_wasbornin_info_34,symTable,"wasbornin.@info.34",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_72_wasbornin_info_35(*rel_72_wasbornin_info_35,symTable,"wasbornin.@info.35",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_73_wasbornin_info_36(*rel_73_wasbornin_info_36,symTable,"wasbornin.@info.36",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_74_wasbornin_info_37(*rel_74_wasbornin_info_37,symTable,"wasbornin.@info.37",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_75_wasbornin_info_38(*rel_75_wasbornin_info_38,symTable,"wasbornin.@info.38",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_76_wasbornin_info_39(*rel_76_wasbornin_info_39,symTable,"wasbornin.@info.39",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_77_wasbornin_info_4(*rel_77_wasbornin_info_4,symTable,"wasbornin.@info.4",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_78_wasbornin_info_40(*rel_78_wasbornin_info_40,symTable,"wasbornin.@info.40",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_79_wasbornin_info_41(*rel_79_wasbornin_info_41,symTable,"wasbornin.@info.41",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_80_wasbornin_info_42(*rel_80_wasbornin_info_42,symTable,"wasbornin.@info.42",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_81_wasbornin_info_43(*rel_81_wasbornin_info_43,symTable,"wasbornin.@info.43",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_82_wasbornin_info_44(*rel_82_wasbornin_info_44,symTable,"wasbornin.@info.44",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_83_wasbornin_info_45(*rel_83_wasbornin_info_45,symTable,"wasbornin.@info.45",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_84_wasbornin_info_46(*rel_84_wasbornin_info_46,symTable,"wasbornin.@info.46",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_85_wasbornin_info_47(*rel_85_wasbornin_info_47,symTable,"wasbornin.@info.47",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_86_wasbornin_info_48(*rel_86_wasbornin_info_48,symTable,"wasbornin.@info.48",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_87_wasbornin_info_49(*rel_87_wasbornin_info_49,symTable,"wasbornin.@info.49",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_88_wasbornin_info_5(*rel_88_wasbornin_info_5,symTable,"wasbornin.@info.5",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_89_wasbornin_info_50(*rel_89_wasbornin_info_50,symTable,"wasbornin.@info.50",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_90_wasbornin_info_51(*rel_90_wasbornin_info_51,symTable,"wasbornin.@info.51",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_91_wasbornin_info_52(*rel_91_wasbornin_info_52,symTable,"wasbornin.@info.52",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_92_wasbornin_info_53(*rel_92_wasbornin_info_53,symTable,"wasbornin.@info.53",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_93_wasbornin_info_54(*rel_93_wasbornin_info_54,symTable,"wasbornin.@info.54",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_94_wasbornin_info_55(*rel_94_wasbornin_info_55,symTable,"wasbornin.@info.55",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_95_wasbornin_info_56(*rel_95_wasbornin_info_56,symTable,"wasbornin.@info.56",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_96_wasbornin_info_57(*rel_96_wasbornin_info_57,symTable,"wasbornin.@info.57",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_97_wasbornin_info_58(*rel_97_wasbornin_info_58,symTable,"wasbornin.@info.58",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_98_wasbornin_info_59(*rel_98_wasbornin_info_59,symTable,"wasbornin.@info.59",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_99_wasbornin_info_6(*rel_99_wasbornin_info_6,symTable,"wasbornin.@info.6",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_100_wasbornin_info_60(*rel_100_wasbornin_info_60,symTable,"wasbornin.@info.60",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_101_wasbornin_info_61(*rel_101_wasbornin_info_61,symTable,"wasbornin.@info.61",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_102_wasbornin_info_62(*rel_102_wasbornin_info_62,symTable,"wasbornin.@info.62",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_103_wasbornin_info_63(*rel_103_wasbornin_info_63,symTable,"wasbornin.@info.63",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_104_wasbornin_info_64(*rel_104_wasbornin_info_64,symTable,"wasbornin.@info.64",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_105_wasbornin_info_65(*rel_105_wasbornin_info_65,symTable,"wasbornin.@info.65",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_106_wasbornin_info_66(*rel_106_wasbornin_info_66,symTable,"wasbornin.@info.66",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_107_wasbornin_info_67(*rel_107_wasbornin_info_67,symTable,"wasbornin.@info.67",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_108_wasbornin_info_68(*rel_108_wasbornin_info_68,symTable,"wasbornin.@info.68",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_109_wasbornin_info_69(*rel_109_wasbornin_info_69,symTable,"wasbornin.@info.69",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_110_wasbornin_info_7(*rel_110_wasbornin_info_7,symTable,"wasbornin.@info.7",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_111_wasbornin_info_70(*rel_111_wasbornin_info_70,symTable,"wasbornin.@info.70",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_112_wasbornin_info_71(*rel_112_wasbornin_info_71,symTable,"wasbornin.@info.71",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_113_wasbornin_info_72(*rel_113_wasbornin_info_72,symTable,"wasbornin.@info.72",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_114_wasbornin_info_73(*rel_114_wasbornin_info_73,symTable,"wasbornin.@info.73",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_115_wasbornin_info_74(*rel_115_wasbornin_info_74,symTable,"wasbornin.@info.74",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_116_wasbornin_info_75(*rel_116_wasbornin_info_75,symTable,"wasbornin.@info.75",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_117_wasbornin_info_76(*rel_117_wasbornin_info_76,symTable,"wasbornin.@info.76",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_118_wasbornin_info_77(*rel_118_wasbornin_info_77,symTable,"wasbornin.@info.77",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_119_wasbornin_info_78(*rel_119_wasbornin_info_78,symTable,"wasbornin.@info.78",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_120_wasbornin_info_79(*rel_120_wasbornin_info_79,symTable,"wasbornin.@info.79",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_121_wasbornin_info_8(*rel_121_wasbornin_info_8,symTable,"wasbornin.@info.8",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_122_wasbornin_info_80(*rel_122_wasbornin_info_80,symTable,"wasbornin.@info.80",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_123_wasbornin_info_81(*rel_123_wasbornin_info_81,symTable,"wasbornin.@info.81",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_124_wasbornin_info_82(*rel_124_wasbornin_info_82,symTable,"wasbornin.@info.82",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_125_wasbornin_info_83(*rel_125_wasbornin_info_83,symTable,"wasbornin.@info.83",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_126_wasbornin_info_84(*rel_126_wasbornin_info_84,symTable,"wasbornin.@info.84",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_127_wasbornin_info_85(*rel_127_wasbornin_info_85,symTable,"wasbornin.@info.85",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_128_wasbornin_info_86(*rel_128_wasbornin_info_86,symTable,"wasbornin.@info.86",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_129_wasbornin_info_87(*rel_129_wasbornin_info_87,symTable,"wasbornin.@info.87",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_130_wasbornin_info_88(*rel_130_wasbornin_info_88,symTable,"wasbornin.@info.88",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_131_wasbornin_info_89(*rel_131_wasbornin_info_89,symTable,"wasbornin.@info.89",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_132_wasbornin_info_9(*rel_132_wasbornin_info_9,symTable,"wasbornin.@info.9",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_133_wasbornin_info_90(*rel_133_wasbornin_info_90,symTable,"wasbornin.@info.90",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_134_wasbornin_info_91(*rel_134_wasbornin_info_91,symTable,"wasbornin.@info.91",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_135_wasbornin_info_92(*rel_135_wasbornin_info_92,symTable,"wasbornin.@info.92",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_136_wasbornin_info_93(*rel_136_wasbornin_info_93,symTable,"wasbornin.@info.93",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_137_wasbornin_info_94(*rel_137_wasbornin_info_94,symTable,"wasbornin.@info.94",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}){
addRelation("Iwasbornin",&wrapper_rel_1_Iwasbornin,true,false);
addRelation("Rule",&wrapper_rel_2_Rule,true,false);
addRelation("livesin",&wrapper_rel_3_livesin,true,false);
addRelation("inv_0",&wrapper_rel_4_inv_0,false,true);
addRelation("wasbornin",&wrapper_rel_7_wasbornin,false,true);
addRelation("inv_0.@info.1",&wrapper_rel_10_inv_0_info_1,false,false);
addRelation("inv_0.@info.10",&wrapper_rel_11_inv_0_info_10,false,false);
addRelation("inv_0.@info.11",&wrapper_rel_12_inv_0_info_11,false,false);
addRelation("inv_0.@info.12",&wrapper_rel_13_inv_0_info_12,false,false);
addRelation("inv_0.@info.13",&wrapper_rel_14_inv_0_info_13,false,false);
addRelation("inv_0.@info.14",&wrapper_rel_15_inv_0_info_14,false,false);
addRelation("inv_0.@info.15",&wrapper_rel_16_inv_0_info_15,false,false);
addRelation("inv_0.@info.16",&wrapper_rel_17_inv_0_info_16,false,false);
addRelation("inv_0.@info.17",&wrapper_rel_18_inv_0_info_17,false,false);
addRelation("inv_0.@info.18",&wrapper_rel_19_inv_0_info_18,false,false);
addRelation("inv_0.@info.19",&wrapper_rel_20_inv_0_info_19,false,false);
addRelation("inv_0.@info.2",&wrapper_rel_21_inv_0_info_2,false,false);
addRelation("inv_0.@info.20",&wrapper_rel_22_inv_0_info_20,false,false);
addRelation("inv_0.@info.21",&wrapper_rel_23_inv_0_info_21,false,false);
addRelation("inv_0.@info.22",&wrapper_rel_24_inv_0_info_22,false,false);
addRelation("inv_0.@info.23",&wrapper_rel_25_inv_0_info_23,false,false);
addRelation("inv_0.@info.24",&wrapper_rel_26_inv_0_info_24,false,false);
addRelation("inv_0.@info.25",&wrapper_rel_27_inv_0_info_25,false,false);
addRelation("inv_0.@info.26",&wrapper_rel_28_inv_0_info_26,false,false);
addRelation("inv_0.@info.27",&wrapper_rel_29_inv_0_info_27,false,false);
addRelation("inv_0.@info.28",&wrapper_rel_30_inv_0_info_28,false,false);
addRelation("inv_0.@info.29",&wrapper_rel_31_inv_0_info_29,false,false);
addRelation("inv_0.@info.3",&wrapper_rel_32_inv_0_info_3,false,false);
addRelation("inv_0.@info.30",&wrapper_rel_33_inv_0_info_30,false,false);
addRelation("inv_0.@info.31",&wrapper_rel_34_inv_0_info_31,false,false);
addRelation("inv_0.@info.32",&wrapper_rel_35_inv_0_info_32,false,false);
addRelation("inv_0.@info.33",&wrapper_rel_36_inv_0_info_33,false,false);
addRelation("inv_0.@info.34",&wrapper_rel_37_inv_0_info_34,false,false);
addRelation("inv_0.@info.4",&wrapper_rel_38_inv_0_info_4,false,false);
addRelation("inv_0.@info.5",&wrapper_rel_39_inv_0_info_5,false,false);
addRelation("inv_0.@info.6",&wrapper_rel_40_inv_0_info_6,false,false);
addRelation("inv_0.@info.7",&wrapper_rel_41_inv_0_info_7,false,false);
addRelation("inv_0.@info.8",&wrapper_rel_42_inv_0_info_8,false,false);
addRelation("inv_0.@info.9",&wrapper_rel_43_inv_0_info_9,false,false);
addRelation("wasbornin.@info.1",&wrapper_rel_44_wasbornin_info_1,false,false);
addRelation("wasbornin.@info.10",&wrapper_rel_45_wasbornin_info_10,false,false);
addRelation("wasbornin.@info.11",&wrapper_rel_46_wasbornin_info_11,false,false);
addRelation("wasbornin.@info.12",&wrapper_rel_47_wasbornin_info_12,false,false);
addRelation("wasbornin.@info.13",&wrapper_rel_48_wasbornin_info_13,false,false);
addRelation("wasbornin.@info.14",&wrapper_rel_49_wasbornin_info_14,false,false);
addRelation("wasbornin.@info.15",&wrapper_rel_50_wasbornin_info_15,false,false);
addRelation("wasbornin.@info.16",&wrapper_rel_51_wasbornin_info_16,false,false);
addRelation("wasbornin.@info.17",&wrapper_rel_52_wasbornin_info_17,false,false);
addRelation("wasbornin.@info.18",&wrapper_rel_53_wasbornin_info_18,false,false);
addRelation("wasbornin.@info.19",&wrapper_rel_54_wasbornin_info_19,false,false);
addRelation("wasbornin.@info.2",&wrapper_rel_55_wasbornin_info_2,false,false);
addRelation("wasbornin.@info.20",&wrapper_rel_56_wasbornin_info_20,false,false);
addRelation("wasbornin.@info.21",&wrapper_rel_57_wasbornin_info_21,false,false);
addRelation("wasbornin.@info.22",&wrapper_rel_58_wasbornin_info_22,false,false);
addRelation("wasbornin.@info.23",&wrapper_rel_59_wasbornin_info_23,false,false);
addRelation("wasbornin.@info.24",&wrapper_rel_60_wasbornin_info_24,false,false);
addRelation("wasbornin.@info.25",&wrapper_rel_61_wasbornin_info_25,false,false);
addRelation("wasbornin.@info.26",&wrapper_rel_62_wasbornin_info_26,false,false);
addRelation("wasbornin.@info.27",&wrapper_rel_63_wasbornin_info_27,false,false);
addRelation("wasbornin.@info.28",&wrapper_rel_64_wasbornin_info_28,false,false);
addRelation("wasbornin.@info.29",&wrapper_rel_65_wasbornin_info_29,false,false);
addRelation("wasbornin.@info.3",&wrapper_rel_66_wasbornin_info_3,false,false);
addRelation("wasbornin.@info.30",&wrapper_rel_67_wasbornin_info_30,false,false);
addRelation("wasbornin.@info.31",&wrapper_rel_68_wasbornin_info_31,false,false);
addRelation("wasbornin.@info.32",&wrapper_rel_69_wasbornin_info_32,false,false);
addRelation("wasbornin.@info.33",&wrapper_rel_70_wasbornin_info_33,false,false);
addRelation("wasbornin.@info.34",&wrapper_rel_71_wasbornin_info_34,false,false);
addRelation("wasbornin.@info.35",&wrapper_rel_72_wasbornin_info_35,false,false);
addRelation("wasbornin.@info.36",&wrapper_rel_73_wasbornin_info_36,false,false);
addRelation("wasbornin.@info.37",&wrapper_rel_74_wasbornin_info_37,false,false);
addRelation("wasbornin.@info.38",&wrapper_rel_75_wasbornin_info_38,false,false);
addRelation("wasbornin.@info.39",&wrapper_rel_76_wasbornin_info_39,false,false);
addRelation("wasbornin.@info.4",&wrapper_rel_77_wasbornin_info_4,false,false);
addRelation("wasbornin.@info.40",&wrapper_rel_78_wasbornin_info_40,false,false);
addRelation("wasbornin.@info.41",&wrapper_rel_79_wasbornin_info_41,false,false);
addRelation("wasbornin.@info.42",&wrapper_rel_80_wasbornin_info_42,false,false);
addRelation("wasbornin.@info.43",&wrapper_rel_81_wasbornin_info_43,false,false);
addRelation("wasbornin.@info.44",&wrapper_rel_82_wasbornin_info_44,false,false);
addRelation("wasbornin.@info.45",&wrapper_rel_83_wasbornin_info_45,false,false);
addRelation("wasbornin.@info.46",&wrapper_rel_84_wasbornin_info_46,false,false);
addRelation("wasbornin.@info.47",&wrapper_rel_85_wasbornin_info_47,false,false);
addRelation("wasbornin.@info.48",&wrapper_rel_86_wasbornin_info_48,false,false);
addRelation("wasbornin.@info.49",&wrapper_rel_87_wasbornin_info_49,false,false);
addRelation("wasbornin.@info.5",&wrapper_rel_88_wasbornin_info_5,false,false);
addRelation("wasbornin.@info.50",&wrapper_rel_89_wasbornin_info_50,false,false);
addRelation("wasbornin.@info.51",&wrapper_rel_90_wasbornin_info_51,false,false);
addRelation("wasbornin.@info.52",&wrapper_rel_91_wasbornin_info_52,false,false);
addRelation("wasbornin.@info.53",&wrapper_rel_92_wasbornin_info_53,false,false);
addRelation("wasbornin.@info.54",&wrapper_rel_93_wasbornin_info_54,false,false);
addRelation("wasbornin.@info.55",&wrapper_rel_94_wasbornin_info_55,false,false);
addRelation("wasbornin.@info.56",&wrapper_rel_95_wasbornin_info_56,false,false);
addRelation("wasbornin.@info.57",&wrapper_rel_96_wasbornin_info_57,false,false);
addRelation("wasbornin.@info.58",&wrapper_rel_97_wasbornin_info_58,false,false);
addRelation("wasbornin.@info.59",&wrapper_rel_98_wasbornin_info_59,false,false);
addRelation("wasbornin.@info.6",&wrapper_rel_99_wasbornin_info_6,false,false);
addRelation("wasbornin.@info.60",&wrapper_rel_100_wasbornin_info_60,false,false);
addRelation("wasbornin.@info.61",&wrapper_rel_101_wasbornin_info_61,false,false);
addRelation("wasbornin.@info.62",&wrapper_rel_102_wasbornin_info_62,false,false);
addRelation("wasbornin.@info.63",&wrapper_rel_103_wasbornin_info_63,false,false);
addRelation("wasbornin.@info.64",&wrapper_rel_104_wasbornin_info_64,false,false);
addRelation("wasbornin.@info.65",&wrapper_rel_105_wasbornin_info_65,false,false);
addRelation("wasbornin.@info.66",&wrapper_rel_106_wasbornin_info_66,false,false);
addRelation("wasbornin.@info.67",&wrapper_rel_107_wasbornin_info_67,false,false);
addRelation("wasbornin.@info.68",&wrapper_rel_108_wasbornin_info_68,false,false);
addRelation("wasbornin.@info.69",&wrapper_rel_109_wasbornin_info_69,false,false);
addRelation("wasbornin.@info.7",&wrapper_rel_110_wasbornin_info_7,false,false);
addRelation("wasbornin.@info.70",&wrapper_rel_111_wasbornin_info_70,false,false);
addRelation("wasbornin.@info.71",&wrapper_rel_112_wasbornin_info_71,false,false);
addRelation("wasbornin.@info.72",&wrapper_rel_113_wasbornin_info_72,false,false);
addRelation("wasbornin.@info.73",&wrapper_rel_114_wasbornin_info_73,false,false);
addRelation("wasbornin.@info.74",&wrapper_rel_115_wasbornin_info_74,false,false);
addRelation("wasbornin.@info.75",&wrapper_rel_116_wasbornin_info_75,false,false);
addRelation("wasbornin.@info.76",&wrapper_rel_117_wasbornin_info_76,false,false);
addRelation("wasbornin.@info.77",&wrapper_rel_118_wasbornin_info_77,false,false);
addRelation("wasbornin.@info.78",&wrapper_rel_119_wasbornin_info_78,false,false);
addRelation("wasbornin.@info.79",&wrapper_rel_120_wasbornin_info_79,false,false);
addRelation("wasbornin.@info.8",&wrapper_rel_121_wasbornin_info_8,false,false);
addRelation("wasbornin.@info.80",&wrapper_rel_122_wasbornin_info_80,false,false);
addRelation("wasbornin.@info.81",&wrapper_rel_123_wasbornin_info_81,false,false);
addRelation("wasbornin.@info.82",&wrapper_rel_124_wasbornin_info_82,false,false);
addRelation("wasbornin.@info.83",&wrapper_rel_125_wasbornin_info_83,false,false);
addRelation("wasbornin.@info.84",&wrapper_rel_126_wasbornin_info_84,false,false);
addRelation("wasbornin.@info.85",&wrapper_rel_127_wasbornin_info_85,false,false);
addRelation("wasbornin.@info.86",&wrapper_rel_128_wasbornin_info_86,false,false);
addRelation("wasbornin.@info.87",&wrapper_rel_129_wasbornin_info_87,false,false);
addRelation("wasbornin.@info.88",&wrapper_rel_130_wasbornin_info_88,false,false);
addRelation("wasbornin.@info.89",&wrapper_rel_131_wasbornin_info_89,false,false);
addRelation("wasbornin.@info.9",&wrapper_rel_132_wasbornin_info_9,false,false);
addRelation("wasbornin.@info.90",&wrapper_rel_133_wasbornin_info_90,false,false);
addRelation("wasbornin.@info.91",&wrapper_rel_134_wasbornin_info_91,false,false);
addRelation("wasbornin.@info.92",&wrapper_rel_135_wasbornin_info_92,false,false);
addRelation("wasbornin.@info.93",&wrapper_rel_136_wasbornin_info_93,false,false);
addRelation("wasbornin.@info.94",&wrapper_rel_137_wasbornin_info_94,false,false);
}
~Sf_souffle_small() {
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Iwasbornin.facts"},{"name","Iwasbornin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_Iwasbornin);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./livesin.facts"},{"name","livesin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_livesin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,1,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(0,_,@level_num_0),
   livesin(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [20:1-20:43])_");
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(0),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(1)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,2,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(1,_,@level_num_0),
   livesin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [21:1-21:43])_");
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(1),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(2)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,4,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(6,_,@level_num_0),
   livesin(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [23:1-23:60])_");
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(6),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(4)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,5,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(7,_,@level_num_0),
   livesin(v0,v1,_,@level_num_1),
   livesin(v1,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [24:1-24:60])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(7),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(5)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,6,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(8,_,@level_num_0),
   livesin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [25:1-25:60])_");
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(8),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(6)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,7,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(9,_,@level_num_0),
   livesin(v1,v0,_,@level_num_1),
   livesin(v0,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [26:1-26:60])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(9),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(7)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,8,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(10,_,@level_num_0),
   livesin(v2,v1,_,@level_num_1),
   livesin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [27:1-27:61])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(10),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(8)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,9,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(11,_,@level_num_0),
   livesin(v1,v2,_,@level_num_1),
   livesin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [28:1-28:61])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(11),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(9)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,10,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(12,_,@level_num_0),
   livesin(v2,v0,_,@level_num_1),
   livesin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [29:1-29:61])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(12),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(10)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,11,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(13,_,@level_num_0),
   livesin(v2,v0,_,@level_num_1),
   livesin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [30:1-30:61])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(13),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(11)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,12,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(14,_,@level_num_0),
   livesin(v0,v2,_,@level_num_1),
   livesin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [31:1-31:61])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(14),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(12)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,13,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(15,_,@level_num_0),
   livesin(v0,v2,_,@level_num_1),
   livesin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [32:1-32:61])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(15),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(13)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,14,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(16,_,@level_num_0),
   livesin(v2,v1,_,@level_num_1),
   livesin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [33:1-33:61])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(16),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(14)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,15,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(17,_,@level_num_0),
   livesin(v1,v2,_,@level_num_1),
   livesin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [34:1-34:61])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(17),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(15)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_4_inv_0->insert(tuple,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
rel_5_delta_inv_0->insertAll(*rel_4_inv_0);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,3,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(5,_,@level_num_0),
   inv_0(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [22:1-22:41])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(5),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_delta_inv_0) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({env0[2], env1[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(3)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,16,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(31,_,@level_num_0),
   livesin(v0,v1,_,@level_num_1),
   inv_0(v1,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [35:1-35:59])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(31),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_5_delta_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(16)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,17,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(32,_,@level_num_0),
   livesin(v1,v0,_,@level_num_1),
   inv_0(v1,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [36:1-36:59])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(32),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_5_delta_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(17)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,18,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(34,_,@level_num_0),
   livesin(v2,v1,_,@level_num_1),
   inv_0(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [37:1-37:59])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(34),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_5_delta_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(18)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,19,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(35,_,@level_num_0),
   livesin(v1,v2,_,@level_num_1),
   inv_0(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [38:1-38:59])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(35),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_5_delta_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(19)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,20,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(36,_,@level_num_0),
   livesin(v2,v0,_,@level_num_1),
   inv_0(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [39:1-39:59])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(36),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_5_delta_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(20)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,21,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(37,_,@level_num_0),
   livesin(v2,v0,_,@level_num_1),
   inv_0(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [40:1-40:59])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(37),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_5_delta_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(21)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,22,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(38,_,@level_num_0),
   livesin(v0,v2,_,@level_num_1),
   inv_0(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [41:1-41:59])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(38),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_5_delta_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(22)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,23,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(39,_,@level_num_0),
   livesin(v0,v2,_,@level_num_1),
   inv_0(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [42:1-42:59])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(39),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_5_delta_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(23)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,24,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(40,_,@level_num_0),
   livesin(v2,v1,_,@level_num_1),
   inv_0(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [43:1-43:59])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(40),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_5_delta_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(24)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,25,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(41,_,@level_num_0),
   livesin(v1,v2,_,@level_num_1),
   inv_0(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [44:1-44:59])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(41),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_5_delta_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(25)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,26,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(68,_,@level_num_0),
   inv_0(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [45:1-45:57])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(68),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_delta_inv_0) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({env0[2], env1[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(26)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,27,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(70,_,@level_num_0),
   inv_0(v2,v1,_,@level_num_1),
   inv_0(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [46:1-46:57])_");
if(!(rel_4_inv_0->empty()) && !(rel_5_delta_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(70),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_delta_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_5_delta_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[0],0,0}}),READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(27)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,27,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(70,_,@level_num_0),
   inv_0(v2,v1,_,@level_num_1),
   inv_0(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [46:1-46:57])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(70),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_5_delta_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(27)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,28,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(71,_,@level_num_0),
   inv_0(v1,v2,_,@level_num_1),
   inv_0(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [47:1-47:57])_");
if(!(rel_4_inv_0->empty()) && !(rel_5_delta_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(71),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_delta_inv_0) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_5_delta_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[1],0,0}}),READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(28)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,28,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(71,_,@level_num_0),
   inv_0(v1,v2,_,@level_num_1),
   inv_0(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [47:1-47:57])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(71),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_5_delta_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(28)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,29,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(72,_,@level_num_0),
   inv_0(v2,v0,_,@level_num_1),
   inv_0(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [48:1-48:57])_");
if(!(rel_4_inv_0->empty()) && !(rel_5_delta_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(72),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_delta_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_5_delta_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[0],0,0}}),READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(29)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,29,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(72,_,@level_num_0),
   inv_0(v2,v0,_,@level_num_1),
   inv_0(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [48:1-48:57])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(72),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_5_delta_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(29)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,30,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(73,_,@level_num_0),
   inv_0(v2,v0,_,@level_num_1),
   inv_0(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [49:1-49:57])_");
if(!(rel_4_inv_0->empty()) && !(rel_5_delta_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(73),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_delta_inv_0) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_5_delta_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(30)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,30,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(73,_,@level_num_0),
   inv_0(v2,v0,_,@level_num_1),
   inv_0(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [49:1-49:57])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(73),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_5_delta_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(30)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,31,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(74,_,@level_num_0),
   inv_0(v0,v2,_,@level_num_1),
   inv_0(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [50:1-50:57])_");
if(!(rel_4_inv_0->empty()) && !(rel_5_delta_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(74),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_delta_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_5_delta_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(31)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,31,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(74,_,@level_num_0),
   inv_0(v0,v2,_,@level_num_1),
   inv_0(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [50:1-50:57])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(74),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_5_delta_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(31)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,32,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(75,_,@level_num_0),
   inv_0(v0,v2,_,@level_num_1),
   inv_0(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [51:1-51:57])_");
if(!(rel_4_inv_0->empty()) && !(rel_5_delta_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(75),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_delta_inv_0) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_5_delta_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[1],0,0}}),READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(32)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,32,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(75,_,@level_num_0),
   inv_0(v0,v2,_,@level_num_1),
   inv_0(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [51:1-51:57])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(75),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_5_delta_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(32)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,33,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(76,_,@level_num_0),
   inv_0(v2,v1,_,@level_num_1),
   inv_0(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [52:1-52:57])_");
if(!(rel_4_inv_0->empty()) && !(rel_5_delta_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(76),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_delta_inv_0) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_5_delta_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(33)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,33,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(76,_,@level_num_0),
   inv_0(v2,v1,_,@level_num_1),
   inv_0(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [52:1-52:57])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(76),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_5_delta_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(33)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,34,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(77,_,@level_num_0),
   inv_0(v1,v2,_,@level_num_1),
   inv_0(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [53:1-53:57])_");
if(!(rel_4_inv_0->empty()) && !(rel_5_delta_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(77),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_delta_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_5_delta_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(34)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,34,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(77,_,@level_num_0),
   inv_0(v1,v2,_,@level_num_1),
   inv_0(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [53:1-53:57])_");
if(!(rel_5_delta_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(77),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt,rel_5_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_6_new_inv_0_op_ctxt,rel_6_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_5_delta_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_5_delta_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(34)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_6_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_6_new_inv_0_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
if(rel_6_new_inv_0->empty()) break;
rel_4_inv_0->insertAll(*rel_6_new_inv_0);
std::swap(rel_5_delta_inv_0, rel_6_new_inv_0);
rel_6_new_inv_0->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_5_delta_inv_0->purge();
if (!isHintsProfilingEnabled()) rel_6_new_inv_0->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./inv_0.csv"},{"name","inv_0"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,1,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(78,_,@level_num_0),
   livesin(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [54:1-54:48])_");
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(78),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(1)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,2,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(79,_,@level_num_0),
   livesin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [55:1-55:48])_");
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(79),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(2)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,3,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(82,_,@level_num_0),
   inv_0(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [56:1-56:46])_");
if(!(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(82),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(3)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,4,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(83,_,@level_num_0),
   inv_0(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [57:1-57:46])_");
if(!(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(83),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(4)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,6,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(86,_,@level_num_0),
   livesin(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [59:1-59:65])_");
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(86),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(6)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,7,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(87,_,@level_num_0),
   livesin(v0,v1,_,@level_num_1),
   livesin(v1,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [60:1-60:65])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(87),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(7)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,8,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(88,_,@level_num_0),
   livesin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [61:1-61:65])_");
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(88),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(8)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,9,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(89,_,@level_num_0),
   livesin(v1,v0,_,@level_num_1),
   livesin(v0,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [62:1-62:65])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(89),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(9)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,10,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(90,_,@level_num_0),
   livesin(v2,v1,_,@level_num_1),
   livesin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [63:1-63:65])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(90),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(10)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,11,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(91,_,@level_num_0),
   livesin(v1,v2,_,@level_num_1),
   livesin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [64:1-64:65])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(91),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(11)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,12,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(92,_,@level_num_0),
   livesin(v2,v0,_,@level_num_1),
   livesin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [65:1-65:65])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(92),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(12)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,13,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(93,_,@level_num_0),
   livesin(v2,v0,_,@level_num_1),
   livesin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [66:1-66:65])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(93),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(13)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,14,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(94,_,@level_num_0),
   livesin(v0,v2,_,@level_num_1),
   livesin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [67:1-67:65])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(94),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(14)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,15,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(95,_,@level_num_0),
   livesin(v0,v2,_,@level_num_1),
   livesin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [68:1-68:65])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(95),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(15)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,16,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(96,_,@level_num_0),
   livesin(v2,v1,_,@level_num_1),
   livesin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [69:1-69:65])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(96),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(16)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,17,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(97,_,@level_num_0),
   livesin(v1,v2,_,@level_num_1),
   livesin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [70:1-70:65])_");
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(97),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(17)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,18,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(102,_,@level_num_0),
   livesin(v2,v1,_,@level_num_1),
   Iwasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [71:1-71:69])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(102),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(18)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,19,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(103,_,@level_num_0),
   livesin(v1,v2,_,@level_num_1),
   Iwasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [72:1-72:69])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(103),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(19)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,20,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(104,_,@level_num_0),
   livesin(v2,v0,_,@level_num_1),
   Iwasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [73:1-73:69])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(104),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(20)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,21,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(105,_,@level_num_0),
   livesin(v2,v0,_,@level_num_1),
   Iwasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [74:1-74:69])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(105),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(21)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,22,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(106,_,@level_num_0),
   livesin(v0,v2,_,@level_num_1),
   Iwasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [75:1-75:69])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(106),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(22)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,23,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(107,_,@level_num_0),
   livesin(v0,v2,_,@level_num_1),
   Iwasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [76:1-76:69])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(107),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(23)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,24,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(108,_,@level_num_0),
   livesin(v2,v1,_,@level_num_1),
   Iwasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [77:1-77:69])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(108),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(24)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,25,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(109,_,@level_num_0),
   livesin(v1,v2,_,@level_num_1),
   Iwasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [78:1-78:69])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(109),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(25)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,26,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(110,_,@level_num_0),
   livesin(v0,v1,_,@level_num_1),
   inv_0(v0,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [79:1-79:64])_");
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(110),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(26)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,27,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(111,_,@level_num_0),
   livesin(v0,v1,_,@level_num_1),
   inv_0(v1,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [80:1-80:64])_");
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(111),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(27)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,28,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(112,_,@level_num_0),
   livesin(v1,v0,_,@level_num_1),
   inv_0(v1,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [81:1-81:64])_");
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(112),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(28)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,29,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(113,_,@level_num_0),
   livesin(v1,v0,_,@level_num_1),
   inv_0(v0,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [82:1-82:64])_");
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(113),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(29)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,30,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(114,_,@level_num_0),
   livesin(v2,v1,_,@level_num_1),
   inv_0(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [83:1-83:64])_");
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(114),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(30)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,31,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(115,_,@level_num_0),
   livesin(v1,v2,_,@level_num_1),
   inv_0(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [84:1-84:64])_");
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(115),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(31)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,32,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(116,_,@level_num_0),
   livesin(v2,v0,_,@level_num_1),
   inv_0(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [85:1-85:64])_");
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(116),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(32)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,33,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(117,_,@level_num_0),
   livesin(v2,v0,_,@level_num_1),
   inv_0(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [86:1-86:64])_");
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(117),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(33)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,34,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(118,_,@level_num_0),
   livesin(v0,v2,_,@level_num_1),
   inv_0(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [87:1-87:64])_");
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(118),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(34)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,35,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(119,_,@level_num_0),
   livesin(v0,v2,_,@level_num_1),
   inv_0(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [88:1-88:64])_");
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(119),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(35)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,36,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(120,_,@level_num_0),
   livesin(v2,v1,_,@level_num_1),
   inv_0(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [89:1-89:64])_");
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(120),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(36)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,37,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(121,_,@level_num_0),
   livesin(v1,v2,_,@level_num_1),
   inv_0(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [90:1-90:64])_");
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(121),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(37)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,48,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(138,_,@level_num_0),
   Iwasbornin(v2,v1,_,@level_num_1),
   Iwasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [101:1-101:72])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(138),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(48)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,49,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(139,_,@level_num_0),
   Iwasbornin(v1,v2,_,@level_num_1),
   Iwasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [102:1-102:72])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(139),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(49)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,50,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(140,_,@level_num_0),
   Iwasbornin(v2,v0,_,@level_num_1),
   Iwasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [103:1-103:72])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(140),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(50)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,51,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(141,_,@level_num_0),
   Iwasbornin(v2,v0,_,@level_num_1),
   Iwasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [104:1-104:72])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(141),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(51)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,52,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(142,_,@level_num_0),
   Iwasbornin(v0,v2,_,@level_num_1),
   Iwasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [105:1-105:72])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(142),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(52)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,53,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(143,_,@level_num_0),
   Iwasbornin(v0,v2,_,@level_num_1),
   Iwasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [106:1-106:72])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(143),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(53)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,54,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(144,_,@level_num_0),
   Iwasbornin(v2,v1,_,@level_num_1),
   Iwasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [107:1-107:72])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(144),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(54)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,55,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(145,_,@level_num_0),
   Iwasbornin(v1,v2,_,@level_num_1),
   Iwasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [108:1-108:72])_");
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(145),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(55)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,64,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(170,_,@level_num_0),
   inv_0(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [117:1-117:62])_");
if(!(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(170),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(64)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,65,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(171,_,@level_num_0),
   inv_0(v0,v1,_,@level_num_1),
   inv_0(v1,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [118:1-118:62])_");
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(171),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(65)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,66,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(172,_,@level_num_0),
   inv_0(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [119:1-119:62])_");
if(!(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(172),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(66)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,67,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(173,_,@level_num_0),
   inv_0(v1,v0,_,@level_num_1),
   inv_0(v0,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [120:1-120:62])_");
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(173),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(67)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,68,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(174,_,@level_num_0),
   inv_0(v2,v1,_,@level_num_1),
   inv_0(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [121:1-121:62])_");
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(174),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(68)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,69,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(175,_,@level_num_0),
   inv_0(v1,v2,_,@level_num_1),
   inv_0(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [122:1-122:62])_");
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(175),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(69)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,70,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(176,_,@level_num_0),
   inv_0(v2,v0,_,@level_num_1),
   inv_0(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [123:1-123:62])_");
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(176),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(70)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,71,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(177,_,@level_num_0),
   inv_0(v2,v0,_,@level_num_1),
   inv_0(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [124:1-124:62])_");
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(177),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(71)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,72,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(178,_,@level_num_0),
   inv_0(v0,v2,_,@level_num_1),
   inv_0(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [125:1-125:62])_");
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(178),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(72)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,73,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(179,_,@level_num_0),
   inv_0(v0,v2,_,@level_num_1),
   inv_0(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [126:1-126:62])_");
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(179),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(73)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,74,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(180,_,@level_num_0),
   inv_0(v2,v1,_,@level_num_1),
   inv_0(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [127:1-127:62])_");
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(180),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(74)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,75,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(181,_,@level_num_0),
   inv_0(v1,v2,_,@level_num_1),
   inv_0(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [128:1-128:62])_");
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(181),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(75)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
rel_8_delta_wasbornin->insertAll(*rel_7_wasbornin);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,5,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(85,_,@level_num_0),
   wasbornin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [58:1-58:50])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(85),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_delta_wasbornin) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({env0[2], env1[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(5)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,38,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(123,_,@level_num_0),
   livesin(v0,v1,_,@level_num_1),
   wasbornin(v1,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [91:1-91:68])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(123),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(38)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,39,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(124,_,@level_num_0),
   livesin(v1,v0,_,@level_num_1),
   wasbornin(v1,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [92:1-92:68])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(124),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(39)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,40,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(126,_,@level_num_0),
   livesin(v2,v1,_,@level_num_1),
   wasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [93:1-93:68])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(126),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(40)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,41,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(127,_,@level_num_0),
   livesin(v1,v2,_,@level_num_1),
   wasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [94:1-94:68])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(127),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(41)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,42,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(128,_,@level_num_0),
   livesin(v2,v0,_,@level_num_1),
   wasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [95:1-95:68])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(128),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(42)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,43,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(129,_,@level_num_0),
   livesin(v2,v0,_,@level_num_1),
   wasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [96:1-96:68])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(129),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(43)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,44,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(130,_,@level_num_0),
   livesin(v0,v2,_,@level_num_1),
   wasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [97:1-97:68])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(130),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(44)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,45,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(131,_,@level_num_0),
   livesin(v0,v2,_,@level_num_1),
   wasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [98:1-98:68])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(131),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(45)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,46,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(132,_,@level_num_0),
   livesin(v2,v1,_,@level_num_1),
   wasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [99:1-99:68])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(132),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(46)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,47,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(133,_,@level_num_0),
   livesin(v1,v2,_,@level_num_1),
   wasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [100:1-100:68])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(133),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_livesin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(47)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,56,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(162,_,@level_num_0),
   Iwasbornin(v2,v1,_,@level_num_1),
   wasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [109:1-109:71])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(162),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(56)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,57,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(163,_,@level_num_0),
   Iwasbornin(v1,v2,_,@level_num_1),
   wasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [110:1-110:71])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(163),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(57)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,58,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(164,_,@level_num_0),
   Iwasbornin(v2,v0,_,@level_num_1),
   wasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [111:1-111:71])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(164),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(58)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,59,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(165,_,@level_num_0),
   Iwasbornin(v2,v0,_,@level_num_1),
   wasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [112:1-112:71])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(165),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(59)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,60,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(166,_,@level_num_0),
   Iwasbornin(v0,v2,_,@level_num_1),
   wasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [113:1-113:71])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(166),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(60)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,61,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(167,_,@level_num_0),
   Iwasbornin(v0,v2,_,@level_num_1),
   wasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [114:1-114:71])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(167),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(61)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,62,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(168,_,@level_num_0),
   Iwasbornin(v2,v1,_,@level_num_1),
   wasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [115:1-115:71])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(168),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(62)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,63,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(169,_,@level_num_0),
   Iwasbornin(v1,v2,_,@level_num_1),
   wasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [116:1-116:71])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(169),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_Iwasbornin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(63)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,76,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(183,_,@level_num_0),
   inv_0(v0,v1,_,@level_num_1),
   wasbornin(v1,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [129:1-129:66])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(183),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(76)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,77,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(184,_,@level_num_0),
   inv_0(v1,v0,_,@level_num_1),
   wasbornin(v1,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [130:1-130:66])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(184),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(77)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,78,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(186,_,@level_num_0),
   inv_0(v2,v1,_,@level_num_1),
   wasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [131:1-131:66])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(186),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(78)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,79,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(187,_,@level_num_0),
   inv_0(v1,v2,_,@level_num_1),
   wasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [132:1-132:66])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(187),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(79)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,80,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(188,_,@level_num_0),
   inv_0(v2,v0,_,@level_num_1),
   wasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [133:1-133:66])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(188),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(80)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,81,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(189,_,@level_num_0),
   inv_0(v2,v0,_,@level_num_1),
   wasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [134:1-134:66])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(189),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(81)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,82,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(190,_,@level_num_0),
   inv_0(v0,v2,_,@level_num_1),
   wasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [135:1-135:66])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(190),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(82)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,83,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(191,_,@level_num_0),
   inv_0(v0,v2,_,@level_num_1),
   wasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [136:1-136:66])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(191),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(83)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,84,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(192,_,@level_num_0),
   inv_0(v2,v1,_,@level_num_1),
   wasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [137:1-137:66])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(192),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(84)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,85,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(193,_,@level_num_0),
   inv_0(v1,v2,_,@level_num_1),
   wasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [138:1-138:66])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(193),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_inv_0) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(85)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,86,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(196,_,@level_num_0),
   wasbornin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [139:1-139:70])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(196),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_delta_wasbornin) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({env0[2], env1[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(86)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,87,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(198,_,@level_num_0),
   wasbornin(v2,v1,_,@level_num_1),
   wasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [140:1-140:70])_");
if(!(rel_7_wasbornin->empty()) && !(rel_8_delta_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(198),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_delta_wasbornin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_7_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_8_delta_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[0],0,0}}),READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(87)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,87,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(198,_,@level_num_0),
   wasbornin(v2,v1,_,@level_num_1),
   wasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [140:1-140:70])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(198),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_7_wasbornin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(87)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,88,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(199,_,@level_num_0),
   wasbornin(v1,v2,_,@level_num_1),
   wasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [141:1-141:70])_");
if(!(rel_7_wasbornin->empty()) && !(rel_8_delta_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(199),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_delta_wasbornin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_7_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_8_delta_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[1],0,0}}),READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(88)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,88,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(199,_,@level_num_0),
   wasbornin(v1,v2,_,@level_num_1),
   wasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [141:1-141:70])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(199),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_7_wasbornin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(88)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,89,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(200,_,@level_num_0),
   wasbornin(v2,v0,_,@level_num_1),
   wasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [142:1-142:70])_");
if(!(rel_7_wasbornin->empty()) && !(rel_8_delta_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(200),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_delta_wasbornin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_7_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_8_delta_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[0],0,0}}),READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(89)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,89,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(200,_,@level_num_0),
   wasbornin(v2,v0,_,@level_num_1),
   wasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [142:1-142:70])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(200),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_7_wasbornin) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(89)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,90,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(201,_,@level_num_0),
   wasbornin(v2,v0,_,@level_num_1),
   wasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [143:1-143:70])_");
if(!(rel_7_wasbornin->empty()) && !(rel_8_delta_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(201),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_delta_wasbornin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_7_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_8_delta_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(90)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,90,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(201,_,@level_num_0),
   wasbornin(v2,v0,_,@level_num_1),
   wasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [143:1-143:70])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(201),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_7_wasbornin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(90)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,91,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(202,_,@level_num_0),
   wasbornin(v0,v2,_,@level_num_1),
   wasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [144:1-144:70])_");
if(!(rel_7_wasbornin->empty()) && !(rel_8_delta_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(202),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_delta_wasbornin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_7_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_8_delta_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(91)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,91,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(202,_,@level_num_0),
   wasbornin(v0,v2,_,@level_num_1),
   wasbornin(v1,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [144:1-144:70])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(202),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_7_wasbornin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(91)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,92,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(203,_,@level_num_0),
   wasbornin(v0,v2,_,@level_num_1),
   wasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [145:1-145:70])_");
if(!(rel_7_wasbornin->empty()) && !(rel_8_delta_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(203),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_delta_wasbornin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_7_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_8_delta_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[1],0,0}}),READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(92)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,92,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(203,_,@level_num_0),
   wasbornin(v0,v2,_,@level_num_1),
   wasbornin(v2,v1,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [145:1-145:70])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(203),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_7_wasbornin) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(92)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,93,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(204,_,@level_num_0),
   wasbornin(v2,v1,_,@level_num_1),
   wasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [146:1-146:70])_");
if(!(rel_7_wasbornin->empty()) && !(rel_8_delta_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(204),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_delta_wasbornin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_7_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_8_delta_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(93)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,93,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(204,_,@level_num_0),
   wasbornin(v2,v1,_,@level_num_1),
   wasbornin(v2,v0,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [146:1-146:70])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(204),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_7_wasbornin) {
const Tuple<RamDomain,4> key({{env1[0],0,0,0}});
auto range = rel_8_delta_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(93)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,94,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(205,_,@level_num_0),
   wasbornin(v1,v2,_,@level_num_1),
   wasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [147:1-147:70])_");
if(!(rel_7_wasbornin->empty()) && !(rel_8_delta_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(205),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_delta_wasbornin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_7_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_8_delta_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(94)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,94,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(205,_,@level_num_0),
   wasbornin(v1,v2,_,@level_num_1),
   wasbornin(v0,v2,_,@level_num_2).
in file /home/johannes_tantow/DatalogLearning/prosynth/locations/rules.dl [147:1-147:70])_");
if(!(rel_8_delta_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(205),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt,rel_8_delta_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt,rel_9_new_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_7_wasbornin) {
const Tuple<RamDomain,4> key({{0,env1[1],0,0}});
auto range = rel_8_delta_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_8_delta_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(94)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_9_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_9_new_wasbornin_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
if(rel_9_new_wasbornin->empty()) break;
rel_7_wasbornin->insertAll(*rel_9_new_wasbornin);
std::swap(rel_8_delta_wasbornin, rel_9_new_wasbornin);
rel_9_new_wasbornin->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_8_delta_wasbornin->purge();
if (!isHintsProfilingEnabled()) rel_9_new_wasbornin->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./wasbornin.csv"},{"name","wasbornin"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_7_wasbornin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.1(1,"v0,v1","Rule","livesin,v0,v1","inv_0(v0,v1) :- 
   Rule(0),
   livesin(v0,v1).").
in file  [0:0-0:0])_");
rel_10_inv_0_info_1->insert(RamDomain(1),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(3));
}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.10(10,"v0,v1","Rule","livesin,v2,v0","livesin,v1,v2","inv_0(v0,v1) :- 
   Rule(12),
   livesin(v2,v0),
   livesin(v1,v2).").
in file  [0:0-0:0])_");
rel_11_inv_0_info_10->insert(RamDomain(10),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(15),RamDomain(18));
}();
/* END STRATUM 6 */
/* BEGIN STRATUM 7 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.11(11,"v0,v1","Rule","livesin,v2,v0","livesin,v2,v1","inv_0(v0,v1) :- 
   Rule(13),
   livesin(v2,v0),
   livesin(v2,v1).").
in file  [0:0-0:0])_");
rel_12_inv_0_info_11->insert(RamDomain(11),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(12),RamDomain(19));
}();
/* END STRATUM 7 */
/* BEGIN STRATUM 8 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.12(12,"v0,v1","Rule","livesin,v0,v2","livesin,v1,v2","inv_0(v0,v1) :- 
   Rule(14),
   livesin(v0,v2),
   livesin(v1,v2).").
in file  [0:0-0:0])_");
rel_13_inv_0_info_12->insert(RamDomain(12),RamDomain(0),RamDomain(1),RamDomain(13),RamDomain(15),RamDomain(20));
}();
/* END STRATUM 8 */
/* BEGIN STRATUM 9 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.13(13,"v0,v1","Rule","livesin,v0,v2","livesin,v2,v1","inv_0(v0,v1) :- 
   Rule(15),
   livesin(v0,v2),
   livesin(v2,v1).").
in file  [0:0-0:0])_");
rel_14_inv_0_info_13->insert(RamDomain(13),RamDomain(0),RamDomain(1),RamDomain(13),RamDomain(12),RamDomain(21));
}();
/* END STRATUM 9 */
/* BEGIN STRATUM 10 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.14(14,"v0,v1","Rule","livesin,v2,v1","livesin,v2,v0","inv_0(v0,v1) :- 
   Rule(16),
   livesin(v2,v1),
   livesin(v2,v0).").
in file  [0:0-0:0])_");
rel_15_inv_0_info_14->insert(RamDomain(14),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(16),RamDomain(22));
}();
/* END STRATUM 10 */
/* BEGIN STRATUM 11 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.15(15,"v0,v1","Rule","livesin,v1,v2","livesin,v0,v2","inv_0(v0,v1) :- 
   Rule(17),
   livesin(v1,v2),
   livesin(v0,v2).").
in file  [0:0-0:0])_");
rel_16_inv_0_info_15->insert(RamDomain(15),RamDomain(0),RamDomain(1),RamDomain(15),RamDomain(13),RamDomain(23));
}();
/* END STRATUM 11 */
/* BEGIN STRATUM 12 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.16(16,"v0,v1","Rule","livesin,v0,v1","inv_0,v1,v0","inv_0(v0,v1) :- 
   Rule(31),
   livesin(v0,v1),
   inv_0(v1,v0).").
in file  [0:0-0:0])_");
rel_17_inv_0_info_16->insert(RamDomain(16),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(6),RamDomain(24));
}();
/* END STRATUM 12 */
/* BEGIN STRATUM 13 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.17(17,"v0,v1","Rule","livesin,v1,v0","inv_0,v1,v0","inv_0(v0,v1) :- 
   Rule(32),
   livesin(v1,v0),
   inv_0(v1,v0).").
in file  [0:0-0:0])_");
rel_18_inv_0_info_17->insert(RamDomain(17),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(6),RamDomain(25));
}();
/* END STRATUM 13 */
/* BEGIN STRATUM 14 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.18(18,"v0,v1","Rule","livesin,v2,v1","inv_0,v0,v2","inv_0(v0,v1) :- 
   Rule(34),
   livesin(v2,v1),
   inv_0(v0,v2).").
in file  [0:0-0:0])_");
rel_19_inv_0_info_18->insert(RamDomain(18),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(26),RamDomain(27));
}();
/* END STRATUM 14 */
/* BEGIN STRATUM 15 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.19(19,"v0,v1","Rule","livesin,v1,v2","inv_0,v2,v0","inv_0(v0,v1) :- 
   Rule(35),
   livesin(v1,v2),
   inv_0(v2,v0).").
in file  [0:0-0:0])_");
rel_20_inv_0_info_19->insert(RamDomain(19),RamDomain(0),RamDomain(1),RamDomain(15),RamDomain(28),RamDomain(29));
}();
/* END STRATUM 15 */
/* BEGIN STRATUM 16 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.2(2,"v0,v1","Rule","livesin,v1,v0","inv_0(v0,v1) :- 
   Rule(1),
   livesin(v1,v0).").
in file  [0:0-0:0])_");
rel_21_inv_0_info_2->insert(RamDomain(2),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(5));
}();
/* END STRATUM 16 */
/* BEGIN STRATUM 17 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.20(20,"v0,v1","Rule","livesin,v2,v0","inv_0,v1,v2","inv_0(v0,v1) :- 
   Rule(36),
   livesin(v2,v0),
   inv_0(v1,v2).").
in file  [0:0-0:0])_");
rel_22_inv_0_info_20->insert(RamDomain(20),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(30),RamDomain(31));
}();
/* END STRATUM 17 */
/* BEGIN STRATUM 18 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.21(21,"v0,v1","Rule","livesin,v2,v0","inv_0,v2,v1","inv_0(v0,v1) :- 
   Rule(37),
   livesin(v2,v0),
   inv_0(v2,v1).").
in file  [0:0-0:0])_");
rel_23_inv_0_info_21->insert(RamDomain(21),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(32),RamDomain(33));
}();
/* END STRATUM 18 */
/* BEGIN STRATUM 19 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.22(22,"v0,v1","Rule","livesin,v0,v2","inv_0,v1,v2","inv_0(v0,v1) :- 
   Rule(38),
   livesin(v0,v2),
   inv_0(v1,v2).").
in file  [0:0-0:0])_");
rel_24_inv_0_info_22->insert(RamDomain(22),RamDomain(0),RamDomain(1),RamDomain(13),RamDomain(30),RamDomain(34));
}();
/* END STRATUM 19 */
/* BEGIN STRATUM 20 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.23(23,"v0,v1","Rule","livesin,v0,v2","inv_0,v2,v1","inv_0(v0,v1) :- 
   Rule(39),
   livesin(v0,v2),
   inv_0(v2,v1).").
in file  [0:0-0:0])_");
rel_25_inv_0_info_23->insert(RamDomain(23),RamDomain(0),RamDomain(1),RamDomain(13),RamDomain(32),RamDomain(35));
}();
/* END STRATUM 20 */
/* BEGIN STRATUM 21 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.24(24,"v0,v1","Rule","livesin,v2,v1","inv_0,v2,v0","inv_0(v0,v1) :- 
   Rule(40),
   livesin(v2,v1),
   inv_0(v2,v0).").
in file  [0:0-0:0])_");
rel_26_inv_0_info_24->insert(RamDomain(24),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(28),RamDomain(36));
}();
/* END STRATUM 21 */
/* BEGIN STRATUM 22 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.25(25,"v0,v1","Rule","livesin,v1,v2","inv_0,v0,v2","inv_0(v0,v1) :- 
   Rule(41),
   livesin(v1,v2),
   inv_0(v0,v2).").
in file  [0:0-0:0])_");
rel_27_inv_0_info_25->insert(RamDomain(25),RamDomain(0),RamDomain(1),RamDomain(15),RamDomain(26),RamDomain(37));
}();
/* END STRATUM 22 */
/* BEGIN STRATUM 23 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.26(26,"v0,v1","Rule","inv_0,v1,v0","inv_0(v0,v1) :- 
   Rule(68),
   inv_0(v1,v0).").
in file  [0:0-0:0])_");
rel_28_inv_0_info_26->insert(RamDomain(26),RamDomain(0),RamDomain(1),RamDomain(6),RamDomain(38));
}();
/* END STRATUM 23 */
/* BEGIN STRATUM 24 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.27(27,"v0,v1","Rule","inv_0,v2,v1","inv_0,v0,v2","inv_0(v0,v1) :- 
   Rule(70),
   inv_0(v2,v1),
   inv_0(v0,v2).").
in file  [0:0-0:0])_");
rel_29_inv_0_info_27->insert(RamDomain(27),RamDomain(0),RamDomain(1),RamDomain(32),RamDomain(26),RamDomain(39));
}();
/* END STRATUM 24 */
/* BEGIN STRATUM 25 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.28(28,"v0,v1","Rule","inv_0,v1,v2","inv_0,v2,v0","inv_0(v0,v1) :- 
   Rule(71),
   inv_0(v1,v2),
   inv_0(v2,v0).").
in file  [0:0-0:0])_");
rel_30_inv_0_info_28->insert(RamDomain(28),RamDomain(0),RamDomain(1),RamDomain(30),RamDomain(28),RamDomain(40));
}();
/* END STRATUM 25 */
/* BEGIN STRATUM 26 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.29(29,"v0,v1","Rule","inv_0,v2,v0","inv_0,v1,v2","inv_0(v0,v1) :- 
   Rule(72),
   inv_0(v2,v0),
   inv_0(v1,v2).").
in file  [0:0-0:0])_");
rel_31_inv_0_info_29->insert(RamDomain(29),RamDomain(0),RamDomain(1),RamDomain(28),RamDomain(30),RamDomain(41));
}();
/* END STRATUM 26 */
/* BEGIN STRATUM 27 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.3(3,"v0,v1","Rule","inv_0,v1,v0","inv_0(v0,v1) :- 
   Rule(5),
   inv_0(v1,v0).").
in file  [0:0-0:0])_");
rel_32_inv_0_info_3->insert(RamDomain(3),RamDomain(0),RamDomain(1),RamDomain(6),RamDomain(7));
}();
/* END STRATUM 27 */
/* BEGIN STRATUM 28 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.30(30,"v0,v1","Rule","inv_0,v2,v0","inv_0,v2,v1","inv_0(v0,v1) :- 
   Rule(73),
   inv_0(v2,v0),
   inv_0(v2,v1).").
in file  [0:0-0:0])_");
rel_33_inv_0_info_30->insert(RamDomain(30),RamDomain(0),RamDomain(1),RamDomain(28),RamDomain(32),RamDomain(42));
}();
/* END STRATUM 28 */
/* BEGIN STRATUM 29 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.31(31,"v0,v1","Rule","inv_0,v0,v2","inv_0,v1,v2","inv_0(v0,v1) :- 
   Rule(74),
   inv_0(v0,v2),
   inv_0(v1,v2).").
in file  [0:0-0:0])_");
rel_34_inv_0_info_31->insert(RamDomain(31),RamDomain(0),RamDomain(1),RamDomain(26),RamDomain(30),RamDomain(43));
}();
/* END STRATUM 29 */
/* BEGIN STRATUM 30 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.32(32,"v0,v1","Rule","inv_0,v0,v2","inv_0,v2,v1","inv_0(v0,v1) :- 
   Rule(75),
   inv_0(v0,v2),
   inv_0(v2,v1).").
in file  [0:0-0:0])_");
rel_35_inv_0_info_32->insert(RamDomain(32),RamDomain(0),RamDomain(1),RamDomain(26),RamDomain(32),RamDomain(44));
}();
/* END STRATUM 30 */
/* BEGIN STRATUM 31 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.33(33,"v0,v1","Rule","inv_0,v2,v1","inv_0,v2,v0","inv_0(v0,v1) :- 
   Rule(76),
   inv_0(v2,v1),
   inv_0(v2,v0).").
in file  [0:0-0:0])_");
rel_36_inv_0_info_33->insert(RamDomain(33),RamDomain(0),RamDomain(1),RamDomain(32),RamDomain(28),RamDomain(45));
}();
/* END STRATUM 31 */
/* BEGIN STRATUM 32 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.34(34,"v0,v1","Rule","inv_0,v1,v2","inv_0,v0,v2","inv_0(v0,v1) :- 
   Rule(77),
   inv_0(v1,v2),
   inv_0(v0,v2).").
in file  [0:0-0:0])_");
rel_37_inv_0_info_34->insert(RamDomain(34),RamDomain(0),RamDomain(1),RamDomain(30),RamDomain(26),RamDomain(46));
}();
/* END STRATUM 32 */
/* BEGIN STRATUM 33 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.4(4,"v0,v1","Rule","livesin,v0,v1","inv_0(v0,v1) :- 
   Rule(6),
   livesin(v0,v1).").
in file  [0:0-0:0])_");
rel_38_inv_0_info_4->insert(RamDomain(4),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(8));
}();
/* END STRATUM 33 */
/* BEGIN STRATUM 34 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.5(5,"v0,v1","Rule","livesin,v0,v1","livesin,v1,v0","inv_0(v0,v1) :- 
   Rule(7),
   livesin(v0,v1),
   livesin(v1,v0).").
in file  [0:0-0:0])_");
rel_39_inv_0_info_5->insert(RamDomain(5),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(4),RamDomain(9));
}();
/* END STRATUM 34 */
/* BEGIN STRATUM 35 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.6(6,"v0,v1","Rule","livesin,v1,v0","inv_0(v0,v1) :- 
   Rule(8),
   livesin(v1,v0).").
in file  [0:0-0:0])_");
rel_40_inv_0_info_6->insert(RamDomain(6),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(10));
}();
/* END STRATUM 35 */
/* BEGIN STRATUM 36 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.7(7,"v0,v1","Rule","livesin,v1,v0","livesin,v0,v1","inv_0(v0,v1) :- 
   Rule(9),
   livesin(v1,v0),
   livesin(v0,v1).").
in file  [0:0-0:0])_");
rel_41_inv_0_info_7->insert(RamDomain(7),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(2),RamDomain(11));
}();
/* END STRATUM 36 */
/* BEGIN STRATUM 37 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.8(8,"v0,v1","Rule","livesin,v2,v1","livesin,v0,v2","inv_0(v0,v1) :- 
   Rule(10),
   livesin(v2,v1),
   livesin(v0,v2).").
in file  [0:0-0:0])_");
rel_42_inv_0_info_8->insert(RamDomain(8),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(13),RamDomain(14));
}();
/* END STRATUM 37 */
/* BEGIN STRATUM 38 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.9(9,"v0,v1","Rule","livesin,v1,v2","livesin,v2,v0","inv_0(v0,v1) :- 
   Rule(11),
   livesin(v1,v2),
   livesin(v2,v0).").
in file  [0:0-0:0])_");
rel_43_inv_0_info_9->insert(RamDomain(9),RamDomain(0),RamDomain(1),RamDomain(15),RamDomain(16),RamDomain(17));
}();
/* END STRATUM 38 */
/* BEGIN STRATUM 39 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.1(1,"v0,v1","Rule","livesin,v0,v1","wasbornin(v0,v1) :- 
   Rule(78),
   livesin(v0,v1).").
in file  [0:0-0:0])_");
rel_44_wasbornin_info_1->insert(RamDomain(1),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(47));
}();
/* END STRATUM 39 */
/* BEGIN STRATUM 40 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.10(10,"v0,v1","Rule","livesin,v2,v1","livesin,v0,v2","wasbornin(v0,v1) :- 
   Rule(90),
   livesin(v2,v1),
   livesin(v0,v2).").
in file  [0:0-0:0])_");
rel_45_wasbornin_info_10->insert(RamDomain(10),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(13),RamDomain(58));
}();
/* END STRATUM 40 */
/* BEGIN STRATUM 41 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.11(11,"v0,v1","Rule","livesin,v1,v2","livesin,v2,v0","wasbornin(v0,v1) :- 
   Rule(91),
   livesin(v1,v2),
   livesin(v2,v0).").
in file  [0:0-0:0])_");
rel_46_wasbornin_info_11->insert(RamDomain(11),RamDomain(0),RamDomain(1),RamDomain(15),RamDomain(16),RamDomain(59));
}();
/* END STRATUM 41 */
/* BEGIN STRATUM 42 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.12(12,"v0,v1","Rule","livesin,v2,v0","livesin,v1,v2","wasbornin(v0,v1) :- 
   Rule(92),
   livesin(v2,v0),
   livesin(v1,v2).").
in file  [0:0-0:0])_");
rel_47_wasbornin_info_12->insert(RamDomain(12),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(15),RamDomain(60));
}();
/* END STRATUM 42 */
/* BEGIN STRATUM 43 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.13(13,"v0,v1","Rule","livesin,v2,v0","livesin,v2,v1","wasbornin(v0,v1) :- 
   Rule(93),
   livesin(v2,v0),
   livesin(v2,v1).").
in file  [0:0-0:0])_");
rel_48_wasbornin_info_13->insert(RamDomain(13),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(12),RamDomain(61));
}();
/* END STRATUM 43 */
/* BEGIN STRATUM 44 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.14(14,"v0,v1","Rule","livesin,v0,v2","livesin,v1,v2","wasbornin(v0,v1) :- 
   Rule(94),
   livesin(v0,v2),
   livesin(v1,v2).").
in file  [0:0-0:0])_");
rel_49_wasbornin_info_14->insert(RamDomain(14),RamDomain(0),RamDomain(1),RamDomain(13),RamDomain(15),RamDomain(62));
}();
/* END STRATUM 44 */
/* BEGIN STRATUM 45 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.15(15,"v0,v1","Rule","livesin,v0,v2","livesin,v2,v1","wasbornin(v0,v1) :- 
   Rule(95),
   livesin(v0,v2),
   livesin(v2,v1).").
in file  [0:0-0:0])_");
rel_50_wasbornin_info_15->insert(RamDomain(15),RamDomain(0),RamDomain(1),RamDomain(13),RamDomain(12),RamDomain(63));
}();
/* END STRATUM 45 */
/* BEGIN STRATUM 46 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.16(16,"v0,v1","Rule","livesin,v2,v1","livesin,v2,v0","wasbornin(v0,v1) :- 
   Rule(96),
   livesin(v2,v1),
   livesin(v2,v0).").
in file  [0:0-0:0])_");
rel_51_wasbornin_info_16->insert(RamDomain(16),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(16),RamDomain(64));
}();
/* END STRATUM 46 */
/* BEGIN STRATUM 47 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.17(17,"v0,v1","Rule","livesin,v1,v2","livesin,v0,v2","wasbornin(v0,v1) :- 
   Rule(97),
   livesin(v1,v2),
   livesin(v0,v2).").
in file  [0:0-0:0])_");
rel_52_wasbornin_info_17->insert(RamDomain(17),RamDomain(0),RamDomain(1),RamDomain(15),RamDomain(13),RamDomain(65));
}();
/* END STRATUM 47 */
/* BEGIN STRATUM 48 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.18(18,"v0,v1","Rule","livesin,v2,v1","Iwasbornin,v0,v2","wasbornin(v0,v1) :- 
   Rule(102),
   livesin(v2,v1),
   Iwasbornin(v0,v2).").
in file  [0:0-0:0])_");
rel_53_wasbornin_info_18->insert(RamDomain(18),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(66),RamDomain(67));
}();
/* END STRATUM 48 */
/* BEGIN STRATUM 49 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.19(19,"v0,v1","Rule","livesin,v1,v2","Iwasbornin,v2,v0","wasbornin(v0,v1) :- 
   Rule(103),
   livesin(v1,v2),
   Iwasbornin(v2,v0).").
in file  [0:0-0:0])_");
rel_54_wasbornin_info_19->insert(RamDomain(19),RamDomain(0),RamDomain(1),RamDomain(15),RamDomain(68),RamDomain(69));
}();
/* END STRATUM 49 */
/* BEGIN STRATUM 50 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.2(2,"v0,v1","Rule","livesin,v1,v0","wasbornin(v0,v1) :- 
   Rule(79),
   livesin(v1,v0).").
in file  [0:0-0:0])_");
rel_55_wasbornin_info_2->insert(RamDomain(2),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(48));
}();
/* END STRATUM 50 */
/* BEGIN STRATUM 51 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.20(20,"v0,v1","Rule","livesin,v2,v0","Iwasbornin,v1,v2","wasbornin(v0,v1) :- 
   Rule(104),
   livesin(v2,v0),
   Iwasbornin(v1,v2).").
in file  [0:0-0:0])_");
rel_56_wasbornin_info_20->insert(RamDomain(20),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(70),RamDomain(71));
}();
/* END STRATUM 51 */
/* BEGIN STRATUM 52 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.21(21,"v0,v1","Rule","livesin,v2,v0","Iwasbornin,v2,v1","wasbornin(v0,v1) :- 
   Rule(105),
   livesin(v2,v0),
   Iwasbornin(v2,v1).").
in file  [0:0-0:0])_");
rel_57_wasbornin_info_21->insert(RamDomain(21),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(72),RamDomain(73));
}();
/* END STRATUM 52 */
/* BEGIN STRATUM 53 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.22(22,"v0,v1","Rule","livesin,v0,v2","Iwasbornin,v1,v2","wasbornin(v0,v1) :- 
   Rule(106),
   livesin(v0,v2),
   Iwasbornin(v1,v2).").
in file  [0:0-0:0])_");
rel_58_wasbornin_info_22->insert(RamDomain(22),RamDomain(0),RamDomain(1),RamDomain(13),RamDomain(70),RamDomain(74));
}();
/* END STRATUM 53 */
/* BEGIN STRATUM 54 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.23(23,"v0,v1","Rule","livesin,v0,v2","Iwasbornin,v2,v1","wasbornin(v0,v1) :- 
   Rule(107),
   livesin(v0,v2),
   Iwasbornin(v2,v1).").
in file  [0:0-0:0])_");
rel_59_wasbornin_info_23->insert(RamDomain(23),RamDomain(0),RamDomain(1),RamDomain(13),RamDomain(72),RamDomain(75));
}();
/* END STRATUM 54 */
/* BEGIN STRATUM 55 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.24(24,"v0,v1","Rule","livesin,v2,v1","Iwasbornin,v2,v0","wasbornin(v0,v1) :- 
   Rule(108),
   livesin(v2,v1),
   Iwasbornin(v2,v0).").
in file  [0:0-0:0])_");
rel_60_wasbornin_info_24->insert(RamDomain(24),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(68),RamDomain(76));
}();
/* END STRATUM 55 */
/* BEGIN STRATUM 56 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.25(25,"v0,v1","Rule","livesin,v1,v2","Iwasbornin,v0,v2","wasbornin(v0,v1) :- 
   Rule(109),
   livesin(v1,v2),
   Iwasbornin(v0,v2).").
in file  [0:0-0:0])_");
rel_61_wasbornin_info_25->insert(RamDomain(25),RamDomain(0),RamDomain(1),RamDomain(15),RamDomain(66),RamDomain(77));
}();
/* END STRATUM 56 */
/* BEGIN STRATUM 57 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.26(26,"v0,v1","Rule","livesin,v0,v1","inv_0,v0,v1","wasbornin(v0,v1) :- 
   Rule(110),
   livesin(v0,v1),
   inv_0(v0,v1).").
in file  [0:0-0:0])_");
rel_62_wasbornin_info_26->insert(RamDomain(26),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(49),RamDomain(78));
}();
/* END STRATUM 57 */
/* BEGIN STRATUM 58 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.27(27,"v0,v1","Rule","livesin,v0,v1","inv_0,v1,v0","wasbornin(v0,v1) :- 
   Rule(111),
   livesin(v0,v1),
   inv_0(v1,v0).").
in file  [0:0-0:0])_");
rel_63_wasbornin_info_27->insert(RamDomain(27),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(6),RamDomain(79));
}();
/* END STRATUM 58 */
/* BEGIN STRATUM 59 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.28(28,"v0,v1","Rule","livesin,v1,v0","inv_0,v1,v0","wasbornin(v0,v1) :- 
   Rule(112),
   livesin(v1,v0),
   inv_0(v1,v0).").
in file  [0:0-0:0])_");
rel_64_wasbornin_info_28->insert(RamDomain(28),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(6),RamDomain(80));
}();
/* END STRATUM 59 */
/* BEGIN STRATUM 60 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.29(29,"v0,v1","Rule","livesin,v1,v0","inv_0,v0,v1","wasbornin(v0,v1) :- 
   Rule(113),
   livesin(v1,v0),
   inv_0(v0,v1).").
in file  [0:0-0:0])_");
rel_65_wasbornin_info_29->insert(RamDomain(29),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(49),RamDomain(81));
}();
/* END STRATUM 60 */
/* BEGIN STRATUM 61 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.3(3,"v0,v1","Rule","inv_0,v0,v1","wasbornin(v0,v1) :- 
   Rule(82),
   inv_0(v0,v1).").
in file  [0:0-0:0])_");
rel_66_wasbornin_info_3->insert(RamDomain(3),RamDomain(0),RamDomain(1),RamDomain(49),RamDomain(50));
}();
/* END STRATUM 61 */
/* BEGIN STRATUM 62 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.30(30,"v0,v1","Rule","livesin,v2,v1","inv_0,v0,v2","wasbornin(v0,v1) :- 
   Rule(114),
   livesin(v2,v1),
   inv_0(v0,v2).").
in file  [0:0-0:0])_");
rel_67_wasbornin_info_30->insert(RamDomain(30),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(26),RamDomain(82));
}();
/* END STRATUM 62 */
/* BEGIN STRATUM 63 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.31(31,"v0,v1","Rule","livesin,v1,v2","inv_0,v2,v0","wasbornin(v0,v1) :- 
   Rule(115),
   livesin(v1,v2),
   inv_0(v2,v0).").
in file  [0:0-0:0])_");
rel_68_wasbornin_info_31->insert(RamDomain(31),RamDomain(0),RamDomain(1),RamDomain(15),RamDomain(28),RamDomain(83));
}();
/* END STRATUM 63 */
/* BEGIN STRATUM 64 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.32(32,"v0,v1","Rule","livesin,v2,v0","inv_0,v1,v2","wasbornin(v0,v1) :- 
   Rule(116),
   livesin(v2,v0),
   inv_0(v1,v2).").
in file  [0:0-0:0])_");
rel_69_wasbornin_info_32->insert(RamDomain(32),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(30),RamDomain(84));
}();
/* END STRATUM 64 */
/* BEGIN STRATUM 65 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.33(33,"v0,v1","Rule","livesin,v2,v0","inv_0,v2,v1","wasbornin(v0,v1) :- 
   Rule(117),
   livesin(v2,v0),
   inv_0(v2,v1).").
in file  [0:0-0:0])_");
rel_70_wasbornin_info_33->insert(RamDomain(33),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(32),RamDomain(85));
}();
/* END STRATUM 65 */
/* BEGIN STRATUM 66 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.34(34,"v0,v1","Rule","livesin,v0,v2","inv_0,v1,v2","wasbornin(v0,v1) :- 
   Rule(118),
   livesin(v0,v2),
   inv_0(v1,v2).").
in file  [0:0-0:0])_");
rel_71_wasbornin_info_34->insert(RamDomain(34),RamDomain(0),RamDomain(1),RamDomain(13),RamDomain(30),RamDomain(86));
}();
/* END STRATUM 66 */
/* BEGIN STRATUM 67 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.35(35,"v0,v1","Rule","livesin,v0,v2","inv_0,v2,v1","wasbornin(v0,v1) :- 
   Rule(119),
   livesin(v0,v2),
   inv_0(v2,v1).").
in file  [0:0-0:0])_");
rel_72_wasbornin_info_35->insert(RamDomain(35),RamDomain(0),RamDomain(1),RamDomain(13),RamDomain(32),RamDomain(87));
}();
/* END STRATUM 67 */
/* BEGIN STRATUM 68 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.36(36,"v0,v1","Rule","livesin,v2,v1","inv_0,v2,v0","wasbornin(v0,v1) :- 
   Rule(120),
   livesin(v2,v1),
   inv_0(v2,v0).").
in file  [0:0-0:0])_");
rel_73_wasbornin_info_36->insert(RamDomain(36),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(28),RamDomain(88));
}();
/* END STRATUM 68 */
/* BEGIN STRATUM 69 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.37(37,"v0,v1","Rule","livesin,v1,v2","inv_0,v0,v2","wasbornin(v0,v1) :- 
   Rule(121),
   livesin(v1,v2),
   inv_0(v0,v2).").
in file  [0:0-0:0])_");
rel_74_wasbornin_info_37->insert(RamDomain(37),RamDomain(0),RamDomain(1),RamDomain(15),RamDomain(26),RamDomain(89));
}();
/* END STRATUM 69 */
/* BEGIN STRATUM 70 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.38(38,"v0,v1","Rule","livesin,v0,v1","wasbornin,v1,v0","wasbornin(v0,v1) :- 
   Rule(123),
   livesin(v0,v1),
   wasbornin(v1,v0).").
in file  [0:0-0:0])_");
rel_75_wasbornin_info_38->insert(RamDomain(38),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(52),RamDomain(90));
}();
/* END STRATUM 70 */
/* BEGIN STRATUM 71 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.39(39,"v0,v1","Rule","livesin,v1,v0","wasbornin,v1,v0","wasbornin(v0,v1) :- 
   Rule(124),
   livesin(v1,v0),
   wasbornin(v1,v0).").
in file  [0:0-0:0])_");
rel_76_wasbornin_info_39->insert(RamDomain(39),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(52),RamDomain(91));
}();
/* END STRATUM 71 */
/* BEGIN STRATUM 72 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.4(4,"v0,v1","Rule","inv_0,v1,v0","wasbornin(v0,v1) :- 
   Rule(83),
   inv_0(v1,v0).").
in file  [0:0-0:0])_");
rel_77_wasbornin_info_4->insert(RamDomain(4),RamDomain(0),RamDomain(1),RamDomain(6),RamDomain(51));
}();
/* END STRATUM 72 */
/* BEGIN STRATUM 73 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.40(40,"v0,v1","Rule","livesin,v2,v1","wasbornin,v0,v2","wasbornin(v0,v1) :- 
   Rule(126),
   livesin(v2,v1),
   wasbornin(v0,v2).").
in file  [0:0-0:0])_");
rel_78_wasbornin_info_40->insert(RamDomain(40),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(92),RamDomain(93));
}();
/* END STRATUM 73 */
/* BEGIN STRATUM 74 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.41(41,"v0,v1","Rule","livesin,v1,v2","wasbornin,v2,v0","wasbornin(v0,v1) :- 
   Rule(127),
   livesin(v1,v2),
   wasbornin(v2,v0).").
in file  [0:0-0:0])_");
rel_79_wasbornin_info_41->insert(RamDomain(41),RamDomain(0),RamDomain(1),RamDomain(15),RamDomain(94),RamDomain(95));
}();
/* END STRATUM 74 */
/* BEGIN STRATUM 75 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.42(42,"v0,v1","Rule","livesin,v2,v0","wasbornin,v1,v2","wasbornin(v0,v1) :- 
   Rule(128),
   livesin(v2,v0),
   wasbornin(v1,v2).").
in file  [0:0-0:0])_");
rel_80_wasbornin_info_42->insert(RamDomain(42),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(96),RamDomain(97));
}();
/* END STRATUM 75 */
/* BEGIN STRATUM 76 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.43(43,"v0,v1","Rule","livesin,v2,v0","wasbornin,v2,v1","wasbornin(v0,v1) :- 
   Rule(129),
   livesin(v2,v0),
   wasbornin(v2,v1).").
in file  [0:0-0:0])_");
rel_81_wasbornin_info_43->insert(RamDomain(43),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(98),RamDomain(99));
}();
/* END STRATUM 76 */
/* BEGIN STRATUM 77 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.44(44,"v0,v1","Rule","livesin,v0,v2","wasbornin,v1,v2","wasbornin(v0,v1) :- 
   Rule(130),
   livesin(v0,v2),
   wasbornin(v1,v2).").
in file  [0:0-0:0])_");
rel_82_wasbornin_info_44->insert(RamDomain(44),RamDomain(0),RamDomain(1),RamDomain(13),RamDomain(96),RamDomain(100));
}();
/* END STRATUM 77 */
/* BEGIN STRATUM 78 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.45(45,"v0,v1","Rule","livesin,v0,v2","wasbornin,v2,v1","wasbornin(v0,v1) :- 
   Rule(131),
   livesin(v0,v2),
   wasbornin(v2,v1).").
in file  [0:0-0:0])_");
rel_83_wasbornin_info_45->insert(RamDomain(45),RamDomain(0),RamDomain(1),RamDomain(13),RamDomain(98),RamDomain(101));
}();
/* END STRATUM 78 */
/* BEGIN STRATUM 79 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.46(46,"v0,v1","Rule","livesin,v2,v1","wasbornin,v2,v0","wasbornin(v0,v1) :- 
   Rule(132),
   livesin(v2,v1),
   wasbornin(v2,v0).").
in file  [0:0-0:0])_");
rel_84_wasbornin_info_46->insert(RamDomain(46),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(94),RamDomain(102));
}();
/* END STRATUM 79 */
/* BEGIN STRATUM 80 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.47(47,"v0,v1","Rule","livesin,v1,v2","wasbornin,v0,v2","wasbornin(v0,v1) :- 
   Rule(133),
   livesin(v1,v2),
   wasbornin(v0,v2).").
in file  [0:0-0:0])_");
rel_85_wasbornin_info_47->insert(RamDomain(47),RamDomain(0),RamDomain(1),RamDomain(15),RamDomain(92),RamDomain(103));
}();
/* END STRATUM 80 */
/* BEGIN STRATUM 81 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.48(48,"v0,v1","Rule","Iwasbornin,v2,v1","Iwasbornin,v0,v2","wasbornin(v0,v1) :- 
   Rule(138),
   Iwasbornin(v2,v1),
   Iwasbornin(v0,v2).").
in file  [0:0-0:0])_");
rel_86_wasbornin_info_48->insert(RamDomain(48),RamDomain(0),RamDomain(1),RamDomain(72),RamDomain(66),RamDomain(104));
}();
/* END STRATUM 81 */
/* BEGIN STRATUM 82 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.49(49,"v0,v1","Rule","Iwasbornin,v1,v2","Iwasbornin,v2,v0","wasbornin(v0,v1) :- 
   Rule(139),
   Iwasbornin(v1,v2),
   Iwasbornin(v2,v0).").
in file  [0:0-0:0])_");
rel_87_wasbornin_info_49->insert(RamDomain(49),RamDomain(0),RamDomain(1),RamDomain(70),RamDomain(68),RamDomain(105));
}();
/* END STRATUM 82 */
/* BEGIN STRATUM 83 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.5(5,"v0,v1","Rule","wasbornin,v1,v0","wasbornin(v0,v1) :- 
   Rule(85),
   wasbornin(v1,v0).").
in file  [0:0-0:0])_");
rel_88_wasbornin_info_5->insert(RamDomain(5),RamDomain(0),RamDomain(1),RamDomain(52),RamDomain(53));
}();
/* END STRATUM 83 */
/* BEGIN STRATUM 84 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.50(50,"v0,v1","Rule","Iwasbornin,v2,v0","Iwasbornin,v1,v2","wasbornin(v0,v1) :- 
   Rule(140),
   Iwasbornin(v2,v0),
   Iwasbornin(v1,v2).").
in file  [0:0-0:0])_");
rel_89_wasbornin_info_50->insert(RamDomain(50),RamDomain(0),RamDomain(1),RamDomain(68),RamDomain(70),RamDomain(106));
}();
/* END STRATUM 84 */
/* BEGIN STRATUM 85 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.51(51,"v0,v1","Rule","Iwasbornin,v2,v0","Iwasbornin,v2,v1","wasbornin(v0,v1) :- 
   Rule(141),
   Iwasbornin(v2,v0),
   Iwasbornin(v2,v1).").
in file  [0:0-0:0])_");
rel_90_wasbornin_info_51->insert(RamDomain(51),RamDomain(0),RamDomain(1),RamDomain(68),RamDomain(72),RamDomain(107));
}();
/* END STRATUM 85 */
/* BEGIN STRATUM 86 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.52(52,"v0,v1","Rule","Iwasbornin,v0,v2","Iwasbornin,v1,v2","wasbornin(v0,v1) :- 
   Rule(142),
   Iwasbornin(v0,v2),
   Iwasbornin(v1,v2).").
in file  [0:0-0:0])_");
rel_91_wasbornin_info_52->insert(RamDomain(52),RamDomain(0),RamDomain(1),RamDomain(66),RamDomain(70),RamDomain(108));
}();
/* END STRATUM 86 */
/* BEGIN STRATUM 87 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.53(53,"v0,v1","Rule","Iwasbornin,v0,v2","Iwasbornin,v2,v1","wasbornin(v0,v1) :- 
   Rule(143),
   Iwasbornin(v0,v2),
   Iwasbornin(v2,v1).").
in file  [0:0-0:0])_");
rel_92_wasbornin_info_53->insert(RamDomain(53),RamDomain(0),RamDomain(1),RamDomain(66),RamDomain(72),RamDomain(109));
}();
/* END STRATUM 87 */
/* BEGIN STRATUM 88 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.54(54,"v0,v1","Rule","Iwasbornin,v2,v1","Iwasbornin,v2,v0","wasbornin(v0,v1) :- 
   Rule(144),
   Iwasbornin(v2,v1),
   Iwasbornin(v2,v0).").
in file  [0:0-0:0])_");
rel_93_wasbornin_info_54->insert(RamDomain(54),RamDomain(0),RamDomain(1),RamDomain(72),RamDomain(68),RamDomain(110));
}();
/* END STRATUM 88 */
/* BEGIN STRATUM 89 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.55(55,"v0,v1","Rule","Iwasbornin,v1,v2","Iwasbornin,v0,v2","wasbornin(v0,v1) :- 
   Rule(145),
   Iwasbornin(v1,v2),
   Iwasbornin(v0,v2).").
in file  [0:0-0:0])_");
rel_94_wasbornin_info_55->insert(RamDomain(55),RamDomain(0),RamDomain(1),RamDomain(70),RamDomain(66),RamDomain(111));
}();
/* END STRATUM 89 */
/* BEGIN STRATUM 90 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.56(56,"v0,v1","Rule","Iwasbornin,v2,v1","wasbornin,v0,v2","wasbornin(v0,v1) :- 
   Rule(162),
   Iwasbornin(v2,v1),
   wasbornin(v0,v2).").
in file  [0:0-0:0])_");
rel_95_wasbornin_info_56->insert(RamDomain(56),RamDomain(0),RamDomain(1),RamDomain(72),RamDomain(92),RamDomain(112));
}();
/* END STRATUM 90 */
/* BEGIN STRATUM 91 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.57(57,"v0,v1","Rule","Iwasbornin,v1,v2","wasbornin,v2,v0","wasbornin(v0,v1) :- 
   Rule(163),
   Iwasbornin(v1,v2),
   wasbornin(v2,v0).").
in file  [0:0-0:0])_");
rel_96_wasbornin_info_57->insert(RamDomain(57),RamDomain(0),RamDomain(1),RamDomain(70),RamDomain(94),RamDomain(113));
}();
/* END STRATUM 91 */
/* BEGIN STRATUM 92 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.58(58,"v0,v1","Rule","Iwasbornin,v2,v0","wasbornin,v1,v2","wasbornin(v0,v1) :- 
   Rule(164),
   Iwasbornin(v2,v0),
   wasbornin(v1,v2).").
in file  [0:0-0:0])_");
rel_97_wasbornin_info_58->insert(RamDomain(58),RamDomain(0),RamDomain(1),RamDomain(68),RamDomain(96),RamDomain(114));
}();
/* END STRATUM 92 */
/* BEGIN STRATUM 93 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.59(59,"v0,v1","Rule","Iwasbornin,v2,v0","wasbornin,v2,v1","wasbornin(v0,v1) :- 
   Rule(165),
   Iwasbornin(v2,v0),
   wasbornin(v2,v1).").
in file  [0:0-0:0])_");
rel_98_wasbornin_info_59->insert(RamDomain(59),RamDomain(0),RamDomain(1),RamDomain(68),RamDomain(98),RamDomain(115));
}();
/* END STRATUM 93 */
/* BEGIN STRATUM 94 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.6(6,"v0,v1","Rule","livesin,v0,v1","wasbornin(v0,v1) :- 
   Rule(86),
   livesin(v0,v1).").
in file  [0:0-0:0])_");
rel_99_wasbornin_info_6->insert(RamDomain(6),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(54));
}();
/* END STRATUM 94 */
/* BEGIN STRATUM 95 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.60(60,"v0,v1","Rule","Iwasbornin,v0,v2","wasbornin,v1,v2","wasbornin(v0,v1) :- 
   Rule(166),
   Iwasbornin(v0,v2),
   wasbornin(v1,v2).").
in file  [0:0-0:0])_");
rel_100_wasbornin_info_60->insert(RamDomain(60),RamDomain(0),RamDomain(1),RamDomain(66),RamDomain(96),RamDomain(116));
}();
/* END STRATUM 95 */
/* BEGIN STRATUM 96 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.61(61,"v0,v1","Rule","Iwasbornin,v0,v2","wasbornin,v2,v1","wasbornin(v0,v1) :- 
   Rule(167),
   Iwasbornin(v0,v2),
   wasbornin(v2,v1).").
in file  [0:0-0:0])_");
rel_101_wasbornin_info_61->insert(RamDomain(61),RamDomain(0),RamDomain(1),RamDomain(66),RamDomain(98),RamDomain(117));
}();
/* END STRATUM 96 */
/* BEGIN STRATUM 97 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.62(62,"v0,v1","Rule","Iwasbornin,v2,v1","wasbornin,v2,v0","wasbornin(v0,v1) :- 
   Rule(168),
   Iwasbornin(v2,v1),
   wasbornin(v2,v0).").
in file  [0:0-0:0])_");
rel_102_wasbornin_info_62->insert(RamDomain(62),RamDomain(0),RamDomain(1),RamDomain(72),RamDomain(94),RamDomain(118));
}();
/* END STRATUM 97 */
/* BEGIN STRATUM 98 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.63(63,"v0,v1","Rule","Iwasbornin,v1,v2","wasbornin,v0,v2","wasbornin(v0,v1) :- 
   Rule(169),
   Iwasbornin(v1,v2),
   wasbornin(v0,v2).").
in file  [0:0-0:0])_");
rel_103_wasbornin_info_63->insert(RamDomain(63),RamDomain(0),RamDomain(1),RamDomain(70),RamDomain(92),RamDomain(119));
}();
/* END STRATUM 98 */
/* BEGIN STRATUM 99 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.64(64,"v0,v1","Rule","inv_0,v0,v1","wasbornin(v0,v1) :- 
   Rule(170),
   inv_0(v0,v1).").
in file  [0:0-0:0])_");
rel_104_wasbornin_info_64->insert(RamDomain(64),RamDomain(0),RamDomain(1),RamDomain(49),RamDomain(120));
}();
/* END STRATUM 99 */
/* BEGIN STRATUM 100 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.65(65,"v0,v1","Rule","inv_0,v0,v1","inv_0,v1,v0","wasbornin(v0,v1) :- 
   Rule(171),
   inv_0(v0,v1),
   inv_0(v1,v0).").
in file  [0:0-0:0])_");
rel_105_wasbornin_info_65->insert(RamDomain(65),RamDomain(0),RamDomain(1),RamDomain(49),RamDomain(6),RamDomain(121));
}();
/* END STRATUM 100 */
/* BEGIN STRATUM 101 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.66(66,"v0,v1","Rule","inv_0,v1,v0","wasbornin(v0,v1) :- 
   Rule(172),
   inv_0(v1,v0).").
in file  [0:0-0:0])_");
rel_106_wasbornin_info_66->insert(RamDomain(66),RamDomain(0),RamDomain(1),RamDomain(6),RamDomain(122));
}();
/* END STRATUM 101 */
/* BEGIN STRATUM 102 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.67(67,"v0,v1","Rule","inv_0,v1,v0","inv_0,v0,v1","wasbornin(v0,v1) :- 
   Rule(173),
   inv_0(v1,v0),
   inv_0(v0,v1).").
in file  [0:0-0:0])_");
rel_107_wasbornin_info_67->insert(RamDomain(67),RamDomain(0),RamDomain(1),RamDomain(6),RamDomain(49),RamDomain(123));
}();
/* END STRATUM 102 */
/* BEGIN STRATUM 103 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.68(68,"v0,v1","Rule","inv_0,v2,v1","inv_0,v0,v2","wasbornin(v0,v1) :- 
   Rule(174),
   inv_0(v2,v1),
   inv_0(v0,v2).").
in file  [0:0-0:0])_");
rel_108_wasbornin_info_68->insert(RamDomain(68),RamDomain(0),RamDomain(1),RamDomain(32),RamDomain(26),RamDomain(124));
}();
/* END STRATUM 103 */
/* BEGIN STRATUM 104 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.69(69,"v0,v1","Rule","inv_0,v1,v2","inv_0,v2,v0","wasbornin(v0,v1) :- 
   Rule(175),
   inv_0(v1,v2),
   inv_0(v2,v0).").
in file  [0:0-0:0])_");
rel_109_wasbornin_info_69->insert(RamDomain(69),RamDomain(0),RamDomain(1),RamDomain(30),RamDomain(28),RamDomain(125));
}();
/* END STRATUM 104 */
/* BEGIN STRATUM 105 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.7(7,"v0,v1","Rule","livesin,v0,v1","livesin,v1,v0","wasbornin(v0,v1) :- 
   Rule(87),
   livesin(v0,v1),
   livesin(v1,v0).").
in file  [0:0-0:0])_");
rel_110_wasbornin_info_7->insert(RamDomain(7),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(4),RamDomain(55));
}();
/* END STRATUM 105 */
/* BEGIN STRATUM 106 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.70(70,"v0,v1","Rule","inv_0,v2,v0","inv_0,v1,v2","wasbornin(v0,v1) :- 
   Rule(176),
   inv_0(v2,v0),
   inv_0(v1,v2).").
in file  [0:0-0:0])_");
rel_111_wasbornin_info_70->insert(RamDomain(70),RamDomain(0),RamDomain(1),RamDomain(28),RamDomain(30),RamDomain(126));
}();
/* END STRATUM 106 */
/* BEGIN STRATUM 107 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.71(71,"v0,v1","Rule","inv_0,v2,v0","inv_0,v2,v1","wasbornin(v0,v1) :- 
   Rule(177),
   inv_0(v2,v0),
   inv_0(v2,v1).").
in file  [0:0-0:0])_");
rel_112_wasbornin_info_71->insert(RamDomain(71),RamDomain(0),RamDomain(1),RamDomain(28),RamDomain(32),RamDomain(127));
}();
/* END STRATUM 107 */
/* BEGIN STRATUM 108 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.72(72,"v0,v1","Rule","inv_0,v0,v2","inv_0,v1,v2","wasbornin(v0,v1) :- 
   Rule(178),
   inv_0(v0,v2),
   inv_0(v1,v2).").
in file  [0:0-0:0])_");
rel_113_wasbornin_info_72->insert(RamDomain(72),RamDomain(0),RamDomain(1),RamDomain(26),RamDomain(30),RamDomain(128));
}();
/* END STRATUM 108 */
/* BEGIN STRATUM 109 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.73(73,"v0,v1","Rule","inv_0,v0,v2","inv_0,v2,v1","wasbornin(v0,v1) :- 
   Rule(179),
   inv_0(v0,v2),
   inv_0(v2,v1).").
in file  [0:0-0:0])_");
rel_114_wasbornin_info_73->insert(RamDomain(73),RamDomain(0),RamDomain(1),RamDomain(26),RamDomain(32),RamDomain(129));
}();
/* END STRATUM 109 */
/* BEGIN STRATUM 110 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.74(74,"v0,v1","Rule","inv_0,v2,v1","inv_0,v2,v0","wasbornin(v0,v1) :- 
   Rule(180),
   inv_0(v2,v1),
   inv_0(v2,v0).").
in file  [0:0-0:0])_");
rel_115_wasbornin_info_74->insert(RamDomain(74),RamDomain(0),RamDomain(1),RamDomain(32),RamDomain(28),RamDomain(130));
}();
/* END STRATUM 110 */
/* BEGIN STRATUM 111 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.75(75,"v0,v1","Rule","inv_0,v1,v2","inv_0,v0,v2","wasbornin(v0,v1) :- 
   Rule(181),
   inv_0(v1,v2),
   inv_0(v0,v2).").
in file  [0:0-0:0])_");
rel_116_wasbornin_info_75->insert(RamDomain(75),RamDomain(0),RamDomain(1),RamDomain(30),RamDomain(26),RamDomain(131));
}();
/* END STRATUM 111 */
/* BEGIN STRATUM 112 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.76(76,"v0,v1","Rule","inv_0,v0,v1","wasbornin,v1,v0","wasbornin(v0,v1) :- 
   Rule(183),
   inv_0(v0,v1),
   wasbornin(v1,v0).").
in file  [0:0-0:0])_");
rel_117_wasbornin_info_76->insert(RamDomain(76),RamDomain(0),RamDomain(1),RamDomain(49),RamDomain(52),RamDomain(132));
}();
/* END STRATUM 112 */
/* BEGIN STRATUM 113 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.77(77,"v0,v1","Rule","inv_0,v1,v0","wasbornin,v1,v0","wasbornin(v0,v1) :- 
   Rule(184),
   inv_0(v1,v0),
   wasbornin(v1,v0).").
in file  [0:0-0:0])_");
rel_118_wasbornin_info_77->insert(RamDomain(77),RamDomain(0),RamDomain(1),RamDomain(6),RamDomain(52),RamDomain(133));
}();
/* END STRATUM 113 */
/* BEGIN STRATUM 114 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.78(78,"v0,v1","Rule","inv_0,v2,v1","wasbornin,v0,v2","wasbornin(v0,v1) :- 
   Rule(186),
   inv_0(v2,v1),
   wasbornin(v0,v2).").
in file  [0:0-0:0])_");
rel_119_wasbornin_info_78->insert(RamDomain(78),RamDomain(0),RamDomain(1),RamDomain(32),RamDomain(92),RamDomain(134));
}();
/* END STRATUM 114 */
/* BEGIN STRATUM 115 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.79(79,"v0,v1","Rule","inv_0,v1,v2","wasbornin,v2,v0","wasbornin(v0,v1) :- 
   Rule(187),
   inv_0(v1,v2),
   wasbornin(v2,v0).").
in file  [0:0-0:0])_");
rel_120_wasbornin_info_79->insert(RamDomain(79),RamDomain(0),RamDomain(1),RamDomain(30),RamDomain(94),RamDomain(135));
}();
/* END STRATUM 115 */
/* BEGIN STRATUM 116 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.8(8,"v0,v1","Rule","livesin,v1,v0","wasbornin(v0,v1) :- 
   Rule(88),
   livesin(v1,v0).").
in file  [0:0-0:0])_");
rel_121_wasbornin_info_8->insert(RamDomain(8),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(56));
}();
/* END STRATUM 116 */
/* BEGIN STRATUM 117 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.80(80,"v0,v1","Rule","inv_0,v2,v0","wasbornin,v1,v2","wasbornin(v0,v1) :- 
   Rule(188),
   inv_0(v2,v0),
   wasbornin(v1,v2).").
in file  [0:0-0:0])_");
rel_122_wasbornin_info_80->insert(RamDomain(80),RamDomain(0),RamDomain(1),RamDomain(28),RamDomain(96),RamDomain(136));
}();
/* END STRATUM 117 */
/* BEGIN STRATUM 118 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.81(81,"v0,v1","Rule","inv_0,v2,v0","wasbornin,v2,v1","wasbornin(v0,v1) :- 
   Rule(189),
   inv_0(v2,v0),
   wasbornin(v2,v1).").
in file  [0:0-0:0])_");
rel_123_wasbornin_info_81->insert(RamDomain(81),RamDomain(0),RamDomain(1),RamDomain(28),RamDomain(98),RamDomain(137));
}();
/* END STRATUM 118 */
/* BEGIN STRATUM 119 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.82(82,"v0,v1","Rule","inv_0,v0,v2","wasbornin,v1,v2","wasbornin(v0,v1) :- 
   Rule(190),
   inv_0(v0,v2),
   wasbornin(v1,v2).").
in file  [0:0-0:0])_");
rel_124_wasbornin_info_82->insert(RamDomain(82),RamDomain(0),RamDomain(1),RamDomain(26),RamDomain(96),RamDomain(138));
}();
/* END STRATUM 119 */
/* BEGIN STRATUM 120 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.83(83,"v0,v1","Rule","inv_0,v0,v2","wasbornin,v2,v1","wasbornin(v0,v1) :- 
   Rule(191),
   inv_0(v0,v2),
   wasbornin(v2,v1).").
in file  [0:0-0:0])_");
rel_125_wasbornin_info_83->insert(RamDomain(83),RamDomain(0),RamDomain(1),RamDomain(26),RamDomain(98),RamDomain(139));
}();
/* END STRATUM 120 */
/* BEGIN STRATUM 121 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.84(84,"v0,v1","Rule","inv_0,v2,v1","wasbornin,v2,v0","wasbornin(v0,v1) :- 
   Rule(192),
   inv_0(v2,v1),
   wasbornin(v2,v0).").
in file  [0:0-0:0])_");
rel_126_wasbornin_info_84->insert(RamDomain(84),RamDomain(0),RamDomain(1),RamDomain(32),RamDomain(94),RamDomain(140));
}();
/* END STRATUM 121 */
/* BEGIN STRATUM 122 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.85(85,"v0,v1","Rule","inv_0,v1,v2","wasbornin,v0,v2","wasbornin(v0,v1) :- 
   Rule(193),
   inv_0(v1,v2),
   wasbornin(v0,v2).").
in file  [0:0-0:0])_");
rel_127_wasbornin_info_85->insert(RamDomain(85),RamDomain(0),RamDomain(1),RamDomain(30),RamDomain(92),RamDomain(141));
}();
/* END STRATUM 122 */
/* BEGIN STRATUM 123 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.86(86,"v0,v1","Rule","wasbornin,v1,v0","wasbornin(v0,v1) :- 
   Rule(196),
   wasbornin(v1,v0).").
in file  [0:0-0:0])_");
rel_128_wasbornin_info_86->insert(RamDomain(86),RamDomain(0),RamDomain(1),RamDomain(52),RamDomain(142));
}();
/* END STRATUM 123 */
/* BEGIN STRATUM 124 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.87(87,"v0,v1","Rule","wasbornin,v2,v1","wasbornin,v0,v2","wasbornin(v0,v1) :- 
   Rule(198),
   wasbornin(v2,v1),
   wasbornin(v0,v2).").
in file  [0:0-0:0])_");
rel_129_wasbornin_info_87->insert(RamDomain(87),RamDomain(0),RamDomain(1),RamDomain(98),RamDomain(92),RamDomain(143));
}();
/* END STRATUM 124 */
/* BEGIN STRATUM 125 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.88(88,"v0,v1","Rule","wasbornin,v1,v2","wasbornin,v2,v0","wasbornin(v0,v1) :- 
   Rule(199),
   wasbornin(v1,v2),
   wasbornin(v2,v0).").
in file  [0:0-0:0])_");
rel_130_wasbornin_info_88->insert(RamDomain(88),RamDomain(0),RamDomain(1),RamDomain(96),RamDomain(94),RamDomain(144));
}();
/* END STRATUM 125 */
/* BEGIN STRATUM 126 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.89(89,"v0,v1","Rule","wasbornin,v2,v0","wasbornin,v1,v2","wasbornin(v0,v1) :- 
   Rule(200),
   wasbornin(v2,v0),
   wasbornin(v1,v2).").
in file  [0:0-0:0])_");
rel_131_wasbornin_info_89->insert(RamDomain(89),RamDomain(0),RamDomain(1),RamDomain(94),RamDomain(96),RamDomain(145));
}();
/* END STRATUM 126 */
/* BEGIN STRATUM 127 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.9(9,"v0,v1","Rule","livesin,v1,v0","livesin,v0,v1","wasbornin(v0,v1) :- 
   Rule(89),
   livesin(v1,v0),
   livesin(v0,v1).").
in file  [0:0-0:0])_");
rel_132_wasbornin_info_9->insert(RamDomain(9),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(2),RamDomain(57));
}();
/* END STRATUM 127 */
/* BEGIN STRATUM 128 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.90(90,"v0,v1","Rule","wasbornin,v2,v0","wasbornin,v2,v1","wasbornin(v0,v1) :- 
   Rule(201),
   wasbornin(v2,v0),
   wasbornin(v2,v1).").
in file  [0:0-0:0])_");
rel_133_wasbornin_info_90->insert(RamDomain(90),RamDomain(0),RamDomain(1),RamDomain(94),RamDomain(98),RamDomain(146));
}();
/* END STRATUM 128 */
/* BEGIN STRATUM 129 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.91(91,"v0,v1","Rule","wasbornin,v0,v2","wasbornin,v1,v2","wasbornin(v0,v1) :- 
   Rule(202),
   wasbornin(v0,v2),
   wasbornin(v1,v2).").
in file  [0:0-0:0])_");
rel_134_wasbornin_info_91->insert(RamDomain(91),RamDomain(0),RamDomain(1),RamDomain(92),RamDomain(96),RamDomain(147));
}();
/* END STRATUM 129 */
/* BEGIN STRATUM 130 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.92(92,"v0,v1","Rule","wasbornin,v0,v2","wasbornin,v2,v1","wasbornin(v0,v1) :- 
   Rule(203),
   wasbornin(v0,v2),
   wasbornin(v2,v1).").
in file  [0:0-0:0])_");
rel_135_wasbornin_info_92->insert(RamDomain(92),RamDomain(0),RamDomain(1),RamDomain(92),RamDomain(98),RamDomain(148));
}();
/* END STRATUM 130 */
/* BEGIN STRATUM 131 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.93(93,"v0,v1","Rule","wasbornin,v2,v1","wasbornin,v2,v0","wasbornin(v0,v1) :- 
   Rule(204),
   wasbornin(v2,v1),
   wasbornin(v2,v0).").
in file  [0:0-0:0])_");
rel_136_wasbornin_info_93->insert(RamDomain(93),RamDomain(0),RamDomain(1),RamDomain(98),RamDomain(94),RamDomain(149));
}();
/* END STRATUM 131 */
/* BEGIN STRATUM 132 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.94(94,"v0,v1","Rule","wasbornin,v1,v2","wasbornin,v0,v2","wasbornin(v0,v1) :- 
   Rule(205),
   wasbornin(v1,v2),
   wasbornin(v0,v2).").
in file  [0:0-0:0])_");
rel_137_wasbornin_info_94->insert(RamDomain(94),RamDomain(0),RamDomain(1),RamDomain(96),RamDomain(92),RamDomain(150));
}();
/* END STRATUM 132 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_Iwasbornin:\n";
rel_1_Iwasbornin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_Rule:\n";
rel_2_Rule->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_livesin:\n";
rel_3_livesin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_inv_0:\n";
rel_4_inv_0->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_delta_inv_0:\n";
rel_5_delta_inv_0->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_new_inv_0:\n";
rel_6_new_inv_0->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_wasbornin:\n";
rel_7_wasbornin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_delta_wasbornin:\n";
rel_8_delta_wasbornin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_new_wasbornin:\n";
rel_9_new_wasbornin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_inv_0_info_1:\n";
rel_10_inv_0_info_1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_inv_0_info_10:\n";
rel_11_inv_0_info_10->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_inv_0_info_11:\n";
rel_12_inv_0_info_11->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_13_inv_0_info_12:\n";
rel_13_inv_0_info_12->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_14_inv_0_info_13:\n";
rel_14_inv_0_info_13->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_15_inv_0_info_14:\n";
rel_15_inv_0_info_14->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_16_inv_0_info_15:\n";
rel_16_inv_0_info_15->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_17_inv_0_info_16:\n";
rel_17_inv_0_info_16->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_18_inv_0_info_17:\n";
rel_18_inv_0_info_17->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_19_inv_0_info_18:\n";
rel_19_inv_0_info_18->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_20_inv_0_info_19:\n";
rel_20_inv_0_info_19->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_21_inv_0_info_2:\n";
rel_21_inv_0_info_2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_22_inv_0_info_20:\n";
rel_22_inv_0_info_20->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_23_inv_0_info_21:\n";
rel_23_inv_0_info_21->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_24_inv_0_info_22:\n";
rel_24_inv_0_info_22->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_25_inv_0_info_23:\n";
rel_25_inv_0_info_23->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_26_inv_0_info_24:\n";
rel_26_inv_0_info_24->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_27_inv_0_info_25:\n";
rel_27_inv_0_info_25->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_28_inv_0_info_26:\n";
rel_28_inv_0_info_26->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_29_inv_0_info_27:\n";
rel_29_inv_0_info_27->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_30_inv_0_info_28:\n";
rel_30_inv_0_info_28->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_31_inv_0_info_29:\n";
rel_31_inv_0_info_29->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_32_inv_0_info_3:\n";
rel_32_inv_0_info_3->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_33_inv_0_info_30:\n";
rel_33_inv_0_info_30->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_34_inv_0_info_31:\n";
rel_34_inv_0_info_31->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_35_inv_0_info_32:\n";
rel_35_inv_0_info_32->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_36_inv_0_info_33:\n";
rel_36_inv_0_info_33->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_37_inv_0_info_34:\n";
rel_37_inv_0_info_34->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_38_inv_0_info_4:\n";
rel_38_inv_0_info_4->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_39_inv_0_info_5:\n";
rel_39_inv_0_info_5->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_40_inv_0_info_6:\n";
rel_40_inv_0_info_6->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_41_inv_0_info_7:\n";
rel_41_inv_0_info_7->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_42_inv_0_info_8:\n";
rel_42_inv_0_info_8->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_43_inv_0_info_9:\n";
rel_43_inv_0_info_9->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_44_wasbornin_info_1:\n";
rel_44_wasbornin_info_1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_45_wasbornin_info_10:\n";
rel_45_wasbornin_info_10->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_46_wasbornin_info_11:\n";
rel_46_wasbornin_info_11->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_47_wasbornin_info_12:\n";
rel_47_wasbornin_info_12->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_48_wasbornin_info_13:\n";
rel_48_wasbornin_info_13->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_49_wasbornin_info_14:\n";
rel_49_wasbornin_info_14->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_50_wasbornin_info_15:\n";
rel_50_wasbornin_info_15->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_51_wasbornin_info_16:\n";
rel_51_wasbornin_info_16->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_52_wasbornin_info_17:\n";
rel_52_wasbornin_info_17->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_53_wasbornin_info_18:\n";
rel_53_wasbornin_info_18->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_54_wasbornin_info_19:\n";
rel_54_wasbornin_info_19->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_55_wasbornin_info_2:\n";
rel_55_wasbornin_info_2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_56_wasbornin_info_20:\n";
rel_56_wasbornin_info_20->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_57_wasbornin_info_21:\n";
rel_57_wasbornin_info_21->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_58_wasbornin_info_22:\n";
rel_58_wasbornin_info_22->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_59_wasbornin_info_23:\n";
rel_59_wasbornin_info_23->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_60_wasbornin_info_24:\n";
rel_60_wasbornin_info_24->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_61_wasbornin_info_25:\n";
rel_61_wasbornin_info_25->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_62_wasbornin_info_26:\n";
rel_62_wasbornin_info_26->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_63_wasbornin_info_27:\n";
rel_63_wasbornin_info_27->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_64_wasbornin_info_28:\n";
rel_64_wasbornin_info_28->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_65_wasbornin_info_29:\n";
rel_65_wasbornin_info_29->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_66_wasbornin_info_3:\n";
rel_66_wasbornin_info_3->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_67_wasbornin_info_30:\n";
rel_67_wasbornin_info_30->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_68_wasbornin_info_31:\n";
rel_68_wasbornin_info_31->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_69_wasbornin_info_32:\n";
rel_69_wasbornin_info_32->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_70_wasbornin_info_33:\n";
rel_70_wasbornin_info_33->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_71_wasbornin_info_34:\n";
rel_71_wasbornin_info_34->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_72_wasbornin_info_35:\n";
rel_72_wasbornin_info_35->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_73_wasbornin_info_36:\n";
rel_73_wasbornin_info_36->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_74_wasbornin_info_37:\n";
rel_74_wasbornin_info_37->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_75_wasbornin_info_38:\n";
rel_75_wasbornin_info_38->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_76_wasbornin_info_39:\n";
rel_76_wasbornin_info_39->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_77_wasbornin_info_4:\n";
rel_77_wasbornin_info_4->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_78_wasbornin_info_40:\n";
rel_78_wasbornin_info_40->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_79_wasbornin_info_41:\n";
rel_79_wasbornin_info_41->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_80_wasbornin_info_42:\n";
rel_80_wasbornin_info_42->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_81_wasbornin_info_43:\n";
rel_81_wasbornin_info_43->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_82_wasbornin_info_44:\n";
rel_82_wasbornin_info_44->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_83_wasbornin_info_45:\n";
rel_83_wasbornin_info_45->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_84_wasbornin_info_46:\n";
rel_84_wasbornin_info_46->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_85_wasbornin_info_47:\n";
rel_85_wasbornin_info_47->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_86_wasbornin_info_48:\n";
rel_86_wasbornin_info_48->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_87_wasbornin_info_49:\n";
rel_87_wasbornin_info_49->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_88_wasbornin_info_5:\n";
rel_88_wasbornin_info_5->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_89_wasbornin_info_50:\n";
rel_89_wasbornin_info_50->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_90_wasbornin_info_51:\n";
rel_90_wasbornin_info_51->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_91_wasbornin_info_52:\n";
rel_91_wasbornin_info_52->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_92_wasbornin_info_53:\n";
rel_92_wasbornin_info_53->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_93_wasbornin_info_54:\n";
rel_93_wasbornin_info_54->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_94_wasbornin_info_55:\n";
rel_94_wasbornin_info_55->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_95_wasbornin_info_56:\n";
rel_95_wasbornin_info_56->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_96_wasbornin_info_57:\n";
rel_96_wasbornin_info_57->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_97_wasbornin_info_58:\n";
rel_97_wasbornin_info_58->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_98_wasbornin_info_59:\n";
rel_98_wasbornin_info_59->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_99_wasbornin_info_6:\n";
rel_99_wasbornin_info_6->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_100_wasbornin_info_60:\n";
rel_100_wasbornin_info_60->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_101_wasbornin_info_61:\n";
rel_101_wasbornin_info_61->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_102_wasbornin_info_62:\n";
rel_102_wasbornin_info_62->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_103_wasbornin_info_63:\n";
rel_103_wasbornin_info_63->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_104_wasbornin_info_64:\n";
rel_104_wasbornin_info_64->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_105_wasbornin_info_65:\n";
rel_105_wasbornin_info_65->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_106_wasbornin_info_66:\n";
rel_106_wasbornin_info_66->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_107_wasbornin_info_67:\n";
rel_107_wasbornin_info_67->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_108_wasbornin_info_68:\n";
rel_108_wasbornin_info_68->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_109_wasbornin_info_69:\n";
rel_109_wasbornin_info_69->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_110_wasbornin_info_7:\n";
rel_110_wasbornin_info_7->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_111_wasbornin_info_70:\n";
rel_111_wasbornin_info_70->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_112_wasbornin_info_71:\n";
rel_112_wasbornin_info_71->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_113_wasbornin_info_72:\n";
rel_113_wasbornin_info_72->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_114_wasbornin_info_73:\n";
rel_114_wasbornin_info_73->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_115_wasbornin_info_74:\n";
rel_115_wasbornin_info_74->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_116_wasbornin_info_75:\n";
rel_116_wasbornin_info_75->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_117_wasbornin_info_76:\n";
rel_117_wasbornin_info_76->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_118_wasbornin_info_77:\n";
rel_118_wasbornin_info_77->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_119_wasbornin_info_78:\n";
rel_119_wasbornin_info_78->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_120_wasbornin_info_79:\n";
rel_120_wasbornin_info_79->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_121_wasbornin_info_8:\n";
rel_121_wasbornin_info_8->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_122_wasbornin_info_80:\n";
rel_122_wasbornin_info_80->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_123_wasbornin_info_81:\n";
rel_123_wasbornin_info_81->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_124_wasbornin_info_82:\n";
rel_124_wasbornin_info_82->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_125_wasbornin_info_83:\n";
rel_125_wasbornin_info_83->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_126_wasbornin_info_84:\n";
rel_126_wasbornin_info_84->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_127_wasbornin_info_85:\n";
rel_127_wasbornin_info_85->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_128_wasbornin_info_86:\n";
rel_128_wasbornin_info_86->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_129_wasbornin_info_87:\n";
rel_129_wasbornin_info_87->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_130_wasbornin_info_88:\n";
rel_130_wasbornin_info_88->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_131_wasbornin_info_89:\n";
rel_131_wasbornin_info_89->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_132_wasbornin_info_9:\n";
rel_132_wasbornin_info_9->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_133_wasbornin_info_90:\n";
rel_133_wasbornin_info_90->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_134_wasbornin_info_91:\n";
rel_134_wasbornin_info_91->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_135_wasbornin_info_92:\n";
rel_135_wasbornin_info_92->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_136_wasbornin_info_93:\n";
rel_136_wasbornin_info_93->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_137_wasbornin_info_94:\n";
rel_137_wasbornin_info_94->printHintStatistics(std::cout,"  ");
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
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./wasbornin.csv"},{"name","wasbornin"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_7_wasbornin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Iwasbornin.facts"},{"name","Iwasbornin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_Iwasbornin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Rule.facts"},{"name","Rule"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->readAll(*rel_2_Rule);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./livesin.facts"},{"name","livesin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_livesin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_Iwasbornin");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_1_Iwasbornin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_Rule");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->writeAll(*rel_2_Rule);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_livesin");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_3_livesin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_4_inv_0");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_7_wasbornin");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_7_wasbornin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
SymbolTable& getSymbolTable() override {
return symTable;
}
void executeSubroutine(std::string name, const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) override {
if (name == "inv_0_10_negation_subproof") {
subproof_0(args, ret, err);
}
if (name == "inv_0_10_subproof") {
subproof_1(args, ret, err);
}
if (name == "inv_0_11_negation_subproof") {
subproof_2(args, ret, err);
}
if (name == "inv_0_11_subproof") {
subproof_3(args, ret, err);
}
if (name == "inv_0_12_negation_subproof") {
subproof_4(args, ret, err);
}
if (name == "inv_0_12_subproof") {
subproof_5(args, ret, err);
}
if (name == "inv_0_13_negation_subproof") {
subproof_6(args, ret, err);
}
if (name == "inv_0_13_subproof") {
subproof_7(args, ret, err);
}
if (name == "inv_0_14_negation_subproof") {
subproof_8(args, ret, err);
}
if (name == "inv_0_14_subproof") {
subproof_9(args, ret, err);
}
if (name == "inv_0_15_negation_subproof") {
subproof_10(args, ret, err);
}
if (name == "inv_0_15_subproof") {
subproof_11(args, ret, err);
}
if (name == "inv_0_16_negation_subproof") {
subproof_12(args, ret, err);
}
if (name == "inv_0_16_subproof") {
subproof_13(args, ret, err);
}
if (name == "inv_0_17_negation_subproof") {
subproof_14(args, ret, err);
}
if (name == "inv_0_17_subproof") {
subproof_15(args, ret, err);
}
if (name == "inv_0_18_negation_subproof") {
subproof_16(args, ret, err);
}
if (name == "inv_0_18_subproof") {
subproof_17(args, ret, err);
}
if (name == "inv_0_19_negation_subproof") {
subproof_18(args, ret, err);
}
if (name == "inv_0_19_subproof") {
subproof_19(args, ret, err);
}
if (name == "inv_0_1_negation_subproof") {
subproof_20(args, ret, err);
}
if (name == "inv_0_1_subproof") {
subproof_21(args, ret, err);
}
if (name == "inv_0_20_negation_subproof") {
subproof_22(args, ret, err);
}
if (name == "inv_0_20_subproof") {
subproof_23(args, ret, err);
}
if (name == "inv_0_21_negation_subproof") {
subproof_24(args, ret, err);
}
if (name == "inv_0_21_subproof") {
subproof_25(args, ret, err);
}
if (name == "inv_0_22_negation_subproof") {
subproof_26(args, ret, err);
}
if (name == "inv_0_22_subproof") {
subproof_27(args, ret, err);
}
if (name == "inv_0_23_negation_subproof") {
subproof_28(args, ret, err);
}
if (name == "inv_0_23_subproof") {
subproof_29(args, ret, err);
}
if (name == "inv_0_24_negation_subproof") {
subproof_30(args, ret, err);
}
if (name == "inv_0_24_subproof") {
subproof_31(args, ret, err);
}
if (name == "inv_0_25_negation_subproof") {
subproof_32(args, ret, err);
}
if (name == "inv_0_25_subproof") {
subproof_33(args, ret, err);
}
if (name == "inv_0_26_negation_subproof") {
subproof_34(args, ret, err);
}
if (name == "inv_0_26_subproof") {
subproof_35(args, ret, err);
}
if (name == "inv_0_27_negation_subproof") {
subproof_36(args, ret, err);
}
if (name == "inv_0_27_subproof") {
subproof_37(args, ret, err);
}
if (name == "inv_0_28_negation_subproof") {
subproof_38(args, ret, err);
}
if (name == "inv_0_28_subproof") {
subproof_39(args, ret, err);
}
if (name == "inv_0_29_negation_subproof") {
subproof_40(args, ret, err);
}
if (name == "inv_0_29_subproof") {
subproof_41(args, ret, err);
}
if (name == "inv_0_2_negation_subproof") {
subproof_42(args, ret, err);
}
if (name == "inv_0_2_subproof") {
subproof_43(args, ret, err);
}
if (name == "inv_0_30_negation_subproof") {
subproof_44(args, ret, err);
}
if (name == "inv_0_30_subproof") {
subproof_45(args, ret, err);
}
if (name == "inv_0_31_negation_subproof") {
subproof_46(args, ret, err);
}
if (name == "inv_0_31_subproof") {
subproof_47(args, ret, err);
}
if (name == "inv_0_32_negation_subproof") {
subproof_48(args, ret, err);
}
if (name == "inv_0_32_subproof") {
subproof_49(args, ret, err);
}
if (name == "inv_0_33_negation_subproof") {
subproof_50(args, ret, err);
}
if (name == "inv_0_33_subproof") {
subproof_51(args, ret, err);
}
if (name == "inv_0_34_negation_subproof") {
subproof_52(args, ret, err);
}
if (name == "inv_0_34_subproof") {
subproof_53(args, ret, err);
}
if (name == "inv_0_3_negation_subproof") {
subproof_54(args, ret, err);
}
if (name == "inv_0_3_subproof") {
subproof_55(args, ret, err);
}
if (name == "inv_0_4_negation_subproof") {
subproof_56(args, ret, err);
}
if (name == "inv_0_4_subproof") {
subproof_57(args, ret, err);
}
if (name == "inv_0_5_negation_subproof") {
subproof_58(args, ret, err);
}
if (name == "inv_0_5_subproof") {
subproof_59(args, ret, err);
}
if (name == "inv_0_6_negation_subproof") {
subproof_60(args, ret, err);
}
if (name == "inv_0_6_subproof") {
subproof_61(args, ret, err);
}
if (name == "inv_0_7_negation_subproof") {
subproof_62(args, ret, err);
}
if (name == "inv_0_7_subproof") {
subproof_63(args, ret, err);
}
if (name == "inv_0_8_negation_subproof") {
subproof_64(args, ret, err);
}
if (name == "inv_0_8_subproof") {
subproof_65(args, ret, err);
}
if (name == "inv_0_9_negation_subproof") {
subproof_66(args, ret, err);
}
if (name == "inv_0_9_subproof") {
subproof_67(args, ret, err);
}
if (name == "wasbornin_10_negation_subproof") {
subproof_68(args, ret, err);
}
if (name == "wasbornin_10_subproof") {
subproof_69(args, ret, err);
}
if (name == "wasbornin_11_negation_subproof") {
subproof_70(args, ret, err);
}
if (name == "wasbornin_11_subproof") {
subproof_71(args, ret, err);
}
if (name == "wasbornin_12_negation_subproof") {
subproof_72(args, ret, err);
}
if (name == "wasbornin_12_subproof") {
subproof_73(args, ret, err);
}
if (name == "wasbornin_13_negation_subproof") {
subproof_74(args, ret, err);
}
if (name == "wasbornin_13_subproof") {
subproof_75(args, ret, err);
}
if (name == "wasbornin_14_negation_subproof") {
subproof_76(args, ret, err);
}
if (name == "wasbornin_14_subproof") {
subproof_77(args, ret, err);
}
if (name == "wasbornin_15_negation_subproof") {
subproof_78(args, ret, err);
}
if (name == "wasbornin_15_subproof") {
subproof_79(args, ret, err);
}
if (name == "wasbornin_16_negation_subproof") {
subproof_80(args, ret, err);
}
if (name == "wasbornin_16_subproof") {
subproof_81(args, ret, err);
}
if (name == "wasbornin_17_negation_subproof") {
subproof_82(args, ret, err);
}
if (name == "wasbornin_17_subproof") {
subproof_83(args, ret, err);
}
if (name == "wasbornin_18_negation_subproof") {
subproof_84(args, ret, err);
}
if (name == "wasbornin_18_subproof") {
subproof_85(args, ret, err);
}
if (name == "wasbornin_19_negation_subproof") {
subproof_86(args, ret, err);
}
if (name == "wasbornin_19_subproof") {
subproof_87(args, ret, err);
}
if (name == "wasbornin_1_negation_subproof") {
subproof_88(args, ret, err);
}
if (name == "wasbornin_1_subproof") {
subproof_89(args, ret, err);
}
if (name == "wasbornin_20_negation_subproof") {
subproof_90(args, ret, err);
}
if (name == "wasbornin_20_subproof") {
subproof_91(args, ret, err);
}
if (name == "wasbornin_21_negation_subproof") {
subproof_92(args, ret, err);
}
if (name == "wasbornin_21_subproof") {
subproof_93(args, ret, err);
}
if (name == "wasbornin_22_negation_subproof") {
subproof_94(args, ret, err);
}
if (name == "wasbornin_22_subproof") {
subproof_95(args, ret, err);
}
if (name == "wasbornin_23_negation_subproof") {
subproof_96(args, ret, err);
}
if (name == "wasbornin_23_subproof") {
subproof_97(args, ret, err);
}
if (name == "wasbornin_24_negation_subproof") {
subproof_98(args, ret, err);
}
if (name == "wasbornin_24_subproof") {
subproof_99(args, ret, err);
}
if (name == "wasbornin_25_negation_subproof") {
subproof_100(args, ret, err);
}
if (name == "wasbornin_25_subproof") {
subproof_101(args, ret, err);
}
if (name == "wasbornin_26_negation_subproof") {
subproof_102(args, ret, err);
}
if (name == "wasbornin_26_subproof") {
subproof_103(args, ret, err);
}
if (name == "wasbornin_27_negation_subproof") {
subproof_104(args, ret, err);
}
if (name == "wasbornin_27_subproof") {
subproof_105(args, ret, err);
}
if (name == "wasbornin_28_negation_subproof") {
subproof_106(args, ret, err);
}
if (name == "wasbornin_28_subproof") {
subproof_107(args, ret, err);
}
if (name == "wasbornin_29_negation_subproof") {
subproof_108(args, ret, err);
}
if (name == "wasbornin_29_subproof") {
subproof_109(args, ret, err);
}
if (name == "wasbornin_2_negation_subproof") {
subproof_110(args, ret, err);
}
if (name == "wasbornin_2_subproof") {
subproof_111(args, ret, err);
}
if (name == "wasbornin_30_negation_subproof") {
subproof_112(args, ret, err);
}
if (name == "wasbornin_30_subproof") {
subproof_113(args, ret, err);
}
if (name == "wasbornin_31_negation_subproof") {
subproof_114(args, ret, err);
}
if (name == "wasbornin_31_subproof") {
subproof_115(args, ret, err);
}
if (name == "wasbornin_32_negation_subproof") {
subproof_116(args, ret, err);
}
if (name == "wasbornin_32_subproof") {
subproof_117(args, ret, err);
}
if (name == "wasbornin_33_negation_subproof") {
subproof_118(args, ret, err);
}
if (name == "wasbornin_33_subproof") {
subproof_119(args, ret, err);
}
if (name == "wasbornin_34_negation_subproof") {
subproof_120(args, ret, err);
}
if (name == "wasbornin_34_subproof") {
subproof_121(args, ret, err);
}
if (name == "wasbornin_35_negation_subproof") {
subproof_122(args, ret, err);
}
if (name == "wasbornin_35_subproof") {
subproof_123(args, ret, err);
}
if (name == "wasbornin_36_negation_subproof") {
subproof_124(args, ret, err);
}
if (name == "wasbornin_36_subproof") {
subproof_125(args, ret, err);
}
if (name == "wasbornin_37_negation_subproof") {
subproof_126(args, ret, err);
}
if (name == "wasbornin_37_subproof") {
subproof_127(args, ret, err);
}
if (name == "wasbornin_38_negation_subproof") {
subproof_128(args, ret, err);
}
if (name == "wasbornin_38_subproof") {
subproof_129(args, ret, err);
}
if (name == "wasbornin_39_negation_subproof") {
subproof_130(args, ret, err);
}
if (name == "wasbornin_39_subproof") {
subproof_131(args, ret, err);
}
if (name == "wasbornin_3_negation_subproof") {
subproof_132(args, ret, err);
}
if (name == "wasbornin_3_subproof") {
subproof_133(args, ret, err);
}
if (name == "wasbornin_40_negation_subproof") {
subproof_134(args, ret, err);
}
if (name == "wasbornin_40_subproof") {
subproof_135(args, ret, err);
}
if (name == "wasbornin_41_negation_subproof") {
subproof_136(args, ret, err);
}
if (name == "wasbornin_41_subproof") {
subproof_137(args, ret, err);
}
if (name == "wasbornin_42_negation_subproof") {
subproof_138(args, ret, err);
}
if (name == "wasbornin_42_subproof") {
subproof_139(args, ret, err);
}
if (name == "wasbornin_43_negation_subproof") {
subproof_140(args, ret, err);
}
if (name == "wasbornin_43_subproof") {
subproof_141(args, ret, err);
}
if (name == "wasbornin_44_negation_subproof") {
subproof_142(args, ret, err);
}
if (name == "wasbornin_44_subproof") {
subproof_143(args, ret, err);
}
if (name == "wasbornin_45_negation_subproof") {
subproof_144(args, ret, err);
}
if (name == "wasbornin_45_subproof") {
subproof_145(args, ret, err);
}
if (name == "wasbornin_46_negation_subproof") {
subproof_146(args, ret, err);
}
if (name == "wasbornin_46_subproof") {
subproof_147(args, ret, err);
}
if (name == "wasbornin_47_negation_subproof") {
subproof_148(args, ret, err);
}
if (name == "wasbornin_47_subproof") {
subproof_149(args, ret, err);
}
if (name == "wasbornin_48_negation_subproof") {
subproof_150(args, ret, err);
}
if (name == "wasbornin_48_subproof") {
subproof_151(args, ret, err);
}
if (name == "wasbornin_49_negation_subproof") {
subproof_152(args, ret, err);
}
if (name == "wasbornin_49_subproof") {
subproof_153(args, ret, err);
}
if (name == "wasbornin_4_negation_subproof") {
subproof_154(args, ret, err);
}
if (name == "wasbornin_4_subproof") {
subproof_155(args, ret, err);
}
if (name == "wasbornin_50_negation_subproof") {
subproof_156(args, ret, err);
}
if (name == "wasbornin_50_subproof") {
subproof_157(args, ret, err);
}
if (name == "wasbornin_51_negation_subproof") {
subproof_158(args, ret, err);
}
if (name == "wasbornin_51_subproof") {
subproof_159(args, ret, err);
}
if (name == "wasbornin_52_negation_subproof") {
subproof_160(args, ret, err);
}
if (name == "wasbornin_52_subproof") {
subproof_161(args, ret, err);
}
if (name == "wasbornin_53_negation_subproof") {
subproof_162(args, ret, err);
}
if (name == "wasbornin_53_subproof") {
subproof_163(args, ret, err);
}
if (name == "wasbornin_54_negation_subproof") {
subproof_164(args, ret, err);
}
if (name == "wasbornin_54_subproof") {
subproof_165(args, ret, err);
}
if (name == "wasbornin_55_negation_subproof") {
subproof_166(args, ret, err);
}
if (name == "wasbornin_55_subproof") {
subproof_167(args, ret, err);
}
if (name == "wasbornin_56_negation_subproof") {
subproof_168(args, ret, err);
}
if (name == "wasbornin_56_subproof") {
subproof_169(args, ret, err);
}
if (name == "wasbornin_57_negation_subproof") {
subproof_170(args, ret, err);
}
if (name == "wasbornin_57_subproof") {
subproof_171(args, ret, err);
}
if (name == "wasbornin_58_negation_subproof") {
subproof_172(args, ret, err);
}
if (name == "wasbornin_58_subproof") {
subproof_173(args, ret, err);
}
if (name == "wasbornin_59_negation_subproof") {
subproof_174(args, ret, err);
}
if (name == "wasbornin_59_subproof") {
subproof_175(args, ret, err);
}
if (name == "wasbornin_5_negation_subproof") {
subproof_176(args, ret, err);
}
if (name == "wasbornin_5_subproof") {
subproof_177(args, ret, err);
}
if (name == "wasbornin_60_negation_subproof") {
subproof_178(args, ret, err);
}
if (name == "wasbornin_60_subproof") {
subproof_179(args, ret, err);
}
if (name == "wasbornin_61_negation_subproof") {
subproof_180(args, ret, err);
}
if (name == "wasbornin_61_subproof") {
subproof_181(args, ret, err);
}
if (name == "wasbornin_62_negation_subproof") {
subproof_182(args, ret, err);
}
if (name == "wasbornin_62_subproof") {
subproof_183(args, ret, err);
}
if (name == "wasbornin_63_negation_subproof") {
subproof_184(args, ret, err);
}
if (name == "wasbornin_63_subproof") {
subproof_185(args, ret, err);
}
if (name == "wasbornin_64_negation_subproof") {
subproof_186(args, ret, err);
}
if (name == "wasbornin_64_subproof") {
subproof_187(args, ret, err);
}
if (name == "wasbornin_65_negation_subproof") {
subproof_188(args, ret, err);
}
if (name == "wasbornin_65_subproof") {
subproof_189(args, ret, err);
}
if (name == "wasbornin_66_negation_subproof") {
subproof_190(args, ret, err);
}
if (name == "wasbornin_66_subproof") {
subproof_191(args, ret, err);
}
if (name == "wasbornin_67_negation_subproof") {
subproof_192(args, ret, err);
}
if (name == "wasbornin_67_subproof") {
subproof_193(args, ret, err);
}
if (name == "wasbornin_68_negation_subproof") {
subproof_194(args, ret, err);
}
if (name == "wasbornin_68_subproof") {
subproof_195(args, ret, err);
}
if (name == "wasbornin_69_negation_subproof") {
subproof_196(args, ret, err);
}
if (name == "wasbornin_69_subproof") {
subproof_197(args, ret, err);
}
if (name == "wasbornin_6_negation_subproof") {
subproof_198(args, ret, err);
}
if (name == "wasbornin_6_subproof") {
subproof_199(args, ret, err);
}
if (name == "wasbornin_70_negation_subproof") {
subproof_200(args, ret, err);
}
if (name == "wasbornin_70_subproof") {
subproof_201(args, ret, err);
}
if (name == "wasbornin_71_negation_subproof") {
subproof_202(args, ret, err);
}
if (name == "wasbornin_71_subproof") {
subproof_203(args, ret, err);
}
if (name == "wasbornin_72_negation_subproof") {
subproof_204(args, ret, err);
}
if (name == "wasbornin_72_subproof") {
subproof_205(args, ret, err);
}
if (name == "wasbornin_73_negation_subproof") {
subproof_206(args, ret, err);
}
if (name == "wasbornin_73_subproof") {
subproof_207(args, ret, err);
}
if (name == "wasbornin_74_negation_subproof") {
subproof_208(args, ret, err);
}
if (name == "wasbornin_74_subproof") {
subproof_209(args, ret, err);
}
if (name == "wasbornin_75_negation_subproof") {
subproof_210(args, ret, err);
}
if (name == "wasbornin_75_subproof") {
subproof_211(args, ret, err);
}
if (name == "wasbornin_76_negation_subproof") {
subproof_212(args, ret, err);
}
if (name == "wasbornin_76_subproof") {
subproof_213(args, ret, err);
}
if (name == "wasbornin_77_negation_subproof") {
subproof_214(args, ret, err);
}
if (name == "wasbornin_77_subproof") {
subproof_215(args, ret, err);
}
if (name == "wasbornin_78_negation_subproof") {
subproof_216(args, ret, err);
}
if (name == "wasbornin_78_subproof") {
subproof_217(args, ret, err);
}
if (name == "wasbornin_79_negation_subproof") {
subproof_218(args, ret, err);
}
if (name == "wasbornin_79_subproof") {
subproof_219(args, ret, err);
}
if (name == "wasbornin_7_negation_subproof") {
subproof_220(args, ret, err);
}
if (name == "wasbornin_7_subproof") {
subproof_221(args, ret, err);
}
if (name == "wasbornin_80_negation_subproof") {
subproof_222(args, ret, err);
}
if (name == "wasbornin_80_subproof") {
subproof_223(args, ret, err);
}
if (name == "wasbornin_81_negation_subproof") {
subproof_224(args, ret, err);
}
if (name == "wasbornin_81_subproof") {
subproof_225(args, ret, err);
}
if (name == "wasbornin_82_negation_subproof") {
subproof_226(args, ret, err);
}
if (name == "wasbornin_82_subproof") {
subproof_227(args, ret, err);
}
if (name == "wasbornin_83_negation_subproof") {
subproof_228(args, ret, err);
}
if (name == "wasbornin_83_subproof") {
subproof_229(args, ret, err);
}
if (name == "wasbornin_84_negation_subproof") {
subproof_230(args, ret, err);
}
if (name == "wasbornin_84_subproof") {
subproof_231(args, ret, err);
}
if (name == "wasbornin_85_negation_subproof") {
subproof_232(args, ret, err);
}
if (name == "wasbornin_85_subproof") {
subproof_233(args, ret, err);
}
if (name == "wasbornin_86_negation_subproof") {
subproof_234(args, ret, err);
}
if (name == "wasbornin_86_subproof") {
subproof_235(args, ret, err);
}
if (name == "wasbornin_87_negation_subproof") {
subproof_236(args, ret, err);
}
if (name == "wasbornin_87_subproof") {
subproof_237(args, ret, err);
}
if (name == "wasbornin_88_negation_subproof") {
subproof_238(args, ret, err);
}
if (name == "wasbornin_88_subproof") {
subproof_239(args, ret, err);
}
if (name == "wasbornin_89_negation_subproof") {
subproof_240(args, ret, err);
}
if (name == "wasbornin_89_subproof") {
subproof_241(args, ret, err);
}
if (name == "wasbornin_8_negation_subproof") {
subproof_242(args, ret, err);
}
if (name == "wasbornin_8_subproof") {
subproof_243(args, ret, err);
}
if (name == "wasbornin_90_negation_subproof") {
subproof_244(args, ret, err);
}
if (name == "wasbornin_90_subproof") {
subproof_245(args, ret, err);
}
if (name == "wasbornin_91_negation_subproof") {
subproof_246(args, ret, err);
}
if (name == "wasbornin_91_subproof") {
subproof_247(args, ret, err);
}
if (name == "wasbornin_92_negation_subproof") {
subproof_248(args, ret, err);
}
if (name == "wasbornin_92_subproof") {
subproof_249(args, ret, err);
}
if (name == "wasbornin_93_negation_subproof") {
subproof_250(args, ret, err);
}
if (name == "wasbornin_93_subproof") {
subproof_251(args, ret, err);
}
if (name == "wasbornin_94_negation_subproof") {
subproof_252(args, ret, err);
}
if (name == "wasbornin_94_subproof") {
subproof_253(args, ret, err);
}
if (name == "wasbornin_9_negation_subproof") {
subproof_254(args, ret, err);
}
if (name == "wasbornin_9_subproof") {
subproof_255(args, ret, err);
}
}
void subproof_0(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(12),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(12));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(12),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(12));
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
void subproof_2(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(13),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(13));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_3(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(13),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(13));
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
void subproof_4(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(14),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(14));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_5(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(14),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(14));
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
void subproof_6(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(15),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(15));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_7(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(15),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(15));
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
ret.push_back(env1[0]);
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
void subproof_8(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(16),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(16));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(16),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(16));
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
void subproof_10(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(17),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(17));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_11(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(17),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(17));
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
void subproof_12(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(31),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(31));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_13(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(31),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(31));
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
ret.push_back(env1[0]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
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
void subproof_14(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(32),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(32));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_15(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(32),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(32));
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
ret.push_back(env1[1]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
err.push_back(false);
ret.push_back(env1[1]);
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
void subproof_16(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(34),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(34));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_17(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(34),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(34));
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
void subproof_18(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(35),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(35));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_19(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(35),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(35));
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
void subproof_20(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(0),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(0));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_21(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(0),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
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
void subproof_22(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(36),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(36));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_23(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(36),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(36));
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
void subproof_24(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(37),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(37));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_25(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(37),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(37));
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
void subproof_26(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(38),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(38));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(38),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(38));
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
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(39),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(39));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_29(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(39),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(39));
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
ret.push_back(env1[0]);
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
void subproof_30(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(40),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(40));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_31(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(40),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(40));
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
void subproof_32(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(41),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(41));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(41),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(41));
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
void subproof_34(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(68),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(68));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_35(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(68),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(68));
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
void subproof_36(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(70),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(70));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_37(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(70),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(70));
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
void subproof_38(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(71),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(71));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_39(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(71),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(71));
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
void subproof_40(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(72),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(72));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_41(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(72),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(72));
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
void subproof_42(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(1),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(1));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_43(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(1),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(1));
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
void subproof_44(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(73),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(73));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_45(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(73),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(73));
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
void subproof_46(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(74),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(74));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_47(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(74),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(74));
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
void subproof_48(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(75),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(75));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_49(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(75),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(75));
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
ret.push_back(env1[0]);
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
void subproof_50(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(76),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(76));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_51(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(76),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(76));
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
void subproof_52(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(77),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(77));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_53(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(77),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(77));
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
void subproof_54(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(5),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(5));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_55(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(5),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(5));
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
void subproof_56(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(6),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(6));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_57(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(6),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(6));
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
void subproof_58(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(7),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(7));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_59(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(7),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(7));
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
ret.push_back(env1[0]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
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
void subproof_60(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(8),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(8));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_61(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(8),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(8));
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
void subproof_62(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(9),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(9));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[1]);
err.push_back(false);
}
();return;
}
void subproof_63(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(9),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(9));
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
void subproof_64(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(10),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(10));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_65(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(10),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(10));
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
void subproof_66(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(11),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(11));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_67(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(11),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(11));
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
void subproof_68(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(90),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(90));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_69(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(90),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(90));
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
void subproof_70(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(91),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(91));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_71(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(91),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(91));
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
void subproof_72(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(92),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(92));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_73(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(92),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(92));
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
void subproof_74(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(93),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(93));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_75(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(93),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(93));
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
void subproof_76(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_77(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(94),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
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
void subproof_78(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(95),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(95));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_79(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(95),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(95));
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
ret.push_back(env1[0]);
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
void subproof_80(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(96),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(96));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_81(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(96),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(96));
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
void subproof_82(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(97),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(97));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_83(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(97),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(97));
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
void subproof_84(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(102),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(102));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_85(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(102),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(102));
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
void subproof_86(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_87(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(103),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
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
void subproof_88(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_89(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(78),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
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
void subproof_90(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_91(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(104),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
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
void subproof_92(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_93(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(105),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
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
void subproof_94(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(106),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(106));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_95(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(106),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(106));
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
void subproof_96(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(107),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(107));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_97(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(107),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(107));
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
ret.push_back(env1[0]);
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
void subproof_98(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_99(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(108),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
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
void subproof_100(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(109),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(109));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_101(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(109),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(109));
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
void subproof_102(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(110),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(110));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[1]);
err.push_back(false);
}
();return;
}
void subproof_103(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(110),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(110));
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
void subproof_104(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(111),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(111));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_105(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(111),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(111));
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
ret.push_back(env1[0]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
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
void subproof_106(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(112),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(112));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_107(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(112),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(112));
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
ret.push_back(env1[1]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
err.push_back(false);
ret.push_back(env1[1]);
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
void subproof_108(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(113),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(113));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[1]);
err.push_back(false);
}
();return;
}
void subproof_109(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(113),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(113));
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
void subproof_110(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(79),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(79));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_111(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(79),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(79));
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
void subproof_112(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(114),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(114));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_113(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(114),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(114));
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
void subproof_114(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(115),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(115));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_115(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(115),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(115));
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
void subproof_116(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(116),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(116));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_117(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(116),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(116));
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
void subproof_118(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(117),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(117));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_119(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(117),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(117));
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
void subproof_120(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(118),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(118));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_121(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(118),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(118));
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
void subproof_122(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(119),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(119));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_123(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(119),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(119));
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
ret.push_back(env1[0]);
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
void subproof_124(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(120),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(120));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_125(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(120),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(120));
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
void subproof_126(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(121),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(121));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_127(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(121),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(121));
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
void subproof_128(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(123),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(123));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_129(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(123),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(123));
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
ret.push_back(env1[0]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
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
void subproof_130(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(124),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(124));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_131(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(124),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(124));
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
ret.push_back(env1[1]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
err.push_back(false);
ret.push_back(env1[1]);
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
void subproof_132(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(82),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(82));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_133(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(82),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(82));
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
void subproof_134(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(126),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(126));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_135(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(126),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(126));
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
void subproof_136(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_137(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(127),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
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
void subproof_138(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_139(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(128),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
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
void subproof_140(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(129),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(129));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_141(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(129),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(129));
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
void subproof_142(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_143(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(130),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
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
void subproof_144(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(131),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(131));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_145(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(131),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(131));
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
ret.push_back(env1[0]);
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
void subproof_146(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(132),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(132));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_147(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(132),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_2(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(132));
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
void subproof_148(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(133),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(133));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_149(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(133),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_livesin->equalRange_1(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(133));
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
void subproof_150(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(138),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(138));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_151(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(138),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(138));
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
void subproof_152(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(139),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(139));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_153(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(139),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(139));
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
void subproof_154(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(83),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(83));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_155(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(83),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(83));
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
void subproof_156(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(140),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(140));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_157(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(140),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(140));
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
void subproof_158(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(141),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(141));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_159(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(141),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(141));
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
void subproof_160(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(142),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(142));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_161(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(142),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(142));
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
void subproof_162(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(143),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(143));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_163(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(143),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(143));
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
ret.push_back(env1[0]);
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
void subproof_164(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(144),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(144));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_165(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(144),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(144));
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
void subproof_166(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(145),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(145));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
void subproof_167(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_Iwasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(145),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(145));
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
void subproof_168(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(162),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(162));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_169(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(162),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(162));
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
void subproof_170(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(163),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(163));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_171(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(163),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(163));
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
void subproof_172(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(164),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(164));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_173(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(164),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(164));
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
void subproof_174(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(165),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(165));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_175(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(165),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(165));
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
void subproof_176(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(85),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(85));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_177(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(85),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(85));
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
void subproof_178(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(166),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(166));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_179(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(166),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(166));
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
void subproof_180(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(167),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(167));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_181(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(167),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(167));
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
ret.push_back(env1[0]);
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
void subproof_182(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(168),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(168));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_183(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(168),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_1_Iwasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(168));
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
void subproof_184(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(169),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(169));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
if(!rel_1_Iwasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_185(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_1_Iwasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(169),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt,rel_1_Iwasbornin->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_1_Iwasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_1_Iwasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(169));
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
void subproof_186(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(170),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(170));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_187(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(170),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(170));
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
void subproof_188(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(171),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(171));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_189(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(171),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(171));
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
ret.push_back(env1[0]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
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
void subproof_190(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_191(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(172),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
ret.push_back(env1[1]);
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
void subproof_192(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(173),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(173));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[1]);
err.push_back(false);
}
();return;
}
void subproof_193(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(173),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(173));
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
void subproof_194(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(174),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(174));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_195(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(174),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(174));
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
void subproof_196(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(175),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(175));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_197(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(175),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(175));
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
void subproof_198(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(86),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(86));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
void subproof_199(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(86),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(86));
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
void subproof_200(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(176),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(176));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_201(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(176),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(176));
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
void subproof_202(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(177),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(177));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_203(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(177),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(177));
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
void subproof_204(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(178),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(178));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_205(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(178),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(178));
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
void subproof_206(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(179),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(179));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_207(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(179),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(179));
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
ret.push_back(env1[0]);
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
void subproof_208(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(180),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(180));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_209(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(180),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(180));
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
void subproof_210(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(181),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(181));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
void subproof_211(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_inv_0->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(181),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(181));
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
void subproof_212(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(183),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(183));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_213(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(183),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(183));
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
ret.push_back(env1[0]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
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
void subproof_214(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(184),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(184));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_215(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(184),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(184));
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
ret.push_back(env1[1]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
err.push_back(false);
ret.push_back(env1[1]);
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
void subproof_216(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(186),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(186));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_217(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(186),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(186));
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
void subproof_218(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(187),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(187));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_219(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(187),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(187));
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
void subproof_220(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(87),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(87));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_221(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(87),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(87));
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
ret.push_back(env1[0]);
err.push_back(false);
ret.push_back(env2[2]);
err.push_back(false);
ret.push_back(env2[3]);
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
void subproof_222(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(188),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(188));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_223(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(188),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(188));
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
void subproof_224(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(189),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(189));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_225(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(189),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(189));
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
void subproof_226(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(190),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(190));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_227(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(190),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(190));
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
void subproof_228(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(191),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(191));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_229(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(191),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(191));
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
ret.push_back(env1[0]);
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
void subproof_230(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(192),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(192));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_231(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(192),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_4_inv_0->equalRange_2(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(192));
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
void subproof_232(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(193),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(193));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
if(!rel_4_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_inv_0_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_233(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_4_inv_0->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(193),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_inv_0_op_ctxt,rel_4_inv_0->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_4_inv_0->equalRange_1(key,READ_OP_CONTEXT(rel_4_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(193));
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
void subproof_234(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(196),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(196));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_235(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(196),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(196));
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
void subproof_236(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(198),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(198));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_237(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(198),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_7_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(198));
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
void subproof_238(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(199),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(199));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_239(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(199),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_7_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(199));
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
void subproof_240(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(200),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(200));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_241(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(200),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_7_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(200));
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
void subproof_242(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(88),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(88));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();return;
}
void subproof_243(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(88),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(88));
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
void subproof_244(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(201),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(201));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_245(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(201),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_7_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(201));
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
void subproof_246(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(202),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(202));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_247(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(202),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_7_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(202));
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
void subproof_248(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(203),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(203));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_249(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(203),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_7_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(203));
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
ret.push_back(env1[0]);
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
void subproof_250(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(204),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(204));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_251(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(204),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_7_wasbornin->equalRange_2(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],(args)[0],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(204));
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
void subproof_252(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(205),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(205));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
if(!rel_7_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt)).empty()) {
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
void subproof_253(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_wasbornin->empty()) && !(rel_7_wasbornin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(205),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_wasbornin_op_ctxt,rel_7_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_7_wasbornin->equalRange_1(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[1],0,0}});
auto range = rel_7_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_7_wasbornin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(205));
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
void subproof_254(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(89),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(89));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[0]);
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
if(!rel_3_livesin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_livesin_op_ctxt)).empty()) {
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
ret.push_back((args)[1]);
err.push_back(false);
}
();return;
}
void subproof_255(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_livesin->empty()) && !(rel_3_livesin->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(89),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_livesin_op_ctxt,rel_3_livesin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_3_livesin->equalRange_3(key,READ_OP_CONTEXT(rel_3_livesin_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(89));
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
};
SouffleProgram *newInstance_souffle_small(){return new Sf_souffle_small;}
SymbolTable *getST_souffle_small(SouffleProgram *p){return &reinterpret_cast<Sf_souffle_small*>(p)->symTable;}

#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_souffle_small: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_souffle_small();
};
public:
factory_Sf_souffle_small() : ProgramFactory("souffle_small"){}
};
static factory_Sf_souffle_small __factory_Sf_souffle_small_instance;
}
#else
}
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(rules.dl)",
R"(.)",
R"(.)",
false,
R"()",
5000,
-1);
if (!opt.parse(argc,argv)) return 1;
souffle::Sf_souffle_small obj;
#if defined(_OPENMP) 
obj.setNumThreads(opt.getNumJobs());

#endif
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir(), opt.getStratumIndex());
explain(obj, false);
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}

#endif
