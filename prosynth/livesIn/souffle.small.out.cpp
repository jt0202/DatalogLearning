
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
	R"_(isCitizenOf,v0,v1)_",
	R"_(livesIn(v0,v1) :- 
   Rule(0),
   isCitizenOf(v0,v1).)_",
	R"_(isCitizenOf,v1,v0)_",
	R"_(livesIn(v0,v1) :- 
   Rule(1),
   isCitizenOf(v1,v0).)_",
	R"_(isInterestedIn,v0,v1)_",
	R"_(livesIn(v0,v1) :- 
   Rule(2),
   isInterestedIn(v0,v1).)_",
	R"_(isInterestedIn,v1,v0)_",
	R"_(livesIn(v0,v1) :- 
   Rule(3),
   isInterestedIn(v1,v0).)_",
	R"_(livesIn,v1,v0)_",
	R"_(livesIn(v0,v1) :- 
   Rule(7),
   livesIn(v1,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(8),
   isCitizenOf(v0,v1).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(9),
   isCitizenOf(v0,v1),
   isCitizenOf(v1,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(10),
   isCitizenOf(v1,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(11),
   isCitizenOf(v1,v0),
   isCitizenOf(v0,v1).)_",
	R"_(isCitizenOf,v2,v1)_",
	R"_(isCitizenOf,v0,v2)_",
	R"_(livesIn(v0,v1) :- 
   Rule(12),
   isCitizenOf(v2,v1),
   isCitizenOf(v0,v2).)_",
	R"_(isCitizenOf,v1,v2)_",
	R"_(isCitizenOf,v2,v0)_",
	R"_(livesIn(v0,v1) :- 
   Rule(13),
   isCitizenOf(v1,v2),
   isCitizenOf(v2,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(14),
   isCitizenOf(v2,v0),
   isCitizenOf(v1,v2).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(17),
   isCitizenOf(v0,v2),
   isCitizenOf(v2,v1).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(20),
   isCitizenOf(v0,v1),
   isInterestedIn(v0,v1).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(21),
   isCitizenOf(v0,v1),
   isInterestedIn(v1,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(22),
   isCitizenOf(v1,v0),
   isInterestedIn(v1,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(23),
   isCitizenOf(v1,v0),
   isInterestedIn(v0,v1).)_",
	R"_(isInterestedIn,v0,v2)_",
	R"_(livesIn(v0,v1) :- 
   Rule(24),
   isCitizenOf(v2,v1),
   isInterestedIn(v0,v2).)_",
	R"_(isInterestedIn,v2,v0)_",
	R"_(livesIn(v0,v1) :- 
   Rule(25),
   isCitizenOf(v1,v2),
   isInterestedIn(v2,v0).)_",
	R"_(isInterestedIn,v1,v2)_",
	R"_(livesIn(v0,v1) :- 
   Rule(26),
   isCitizenOf(v2,v0),
   isInterestedIn(v1,v2).)_",
	R"_(isInterestedIn,v2,v1)_",
	R"_(livesIn(v0,v1) :- 
   Rule(29),
   isCitizenOf(v0,v2),
   isInterestedIn(v2,v1).)_",
	R"_(IlivesIn,v2,v0)_",
	R"_(livesIn(v0,v1) :- 
   Rule(37),
   isCitizenOf(v1,v2),
   IlivesIn(v2,v0).)_",
	R"_(IlivesIn,v1,v2)_",
	R"_(livesIn(v0,v1) :- 
   Rule(38),
   isCitizenOf(v2,v0),
   IlivesIn(v1,v2).)_",
	R"_(IlivesIn,v2,v1)_",
	R"_(livesIn(v0,v1) :- 
   Rule(41),
   isCitizenOf(v0,v2),
   IlivesIn(v2,v1).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(45),
   isCitizenOf(v0,v1),
   livesIn(v1,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(46),
   isCitizenOf(v1,v0),
   livesIn(v1,v0).)_",
	R"_(livesIn,v2,v0)_",
	R"_(livesIn(v0,v1) :- 
   Rule(49),
   isCitizenOf(v1,v2),
   livesIn(v2,v0).)_",
	R"_(livesIn,v1,v2)_",
	R"_(livesIn(v0,v1) :- 
   Rule(50),
   isCitizenOf(v2,v0),
   livesIn(v1,v2).)_",
	R"_(livesIn,v2,v1)_",
	R"_(livesIn(v0,v1) :- 
   Rule(53),
   isCitizenOf(v0,v2),
   livesIn(v2,v1).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(56),
   isInterestedIn(v0,v1).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(57),
   isInterestedIn(v0,v1),
   isInterestedIn(v1,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(58),
   isInterestedIn(v1,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(59),
   isInterestedIn(v1,v0),
   isInterestedIn(v0,v1).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(60),
   isInterestedIn(v2,v1),
   isInterestedIn(v0,v2).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(61),
   isInterestedIn(v1,v2),
   isInterestedIn(v2,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(62),
   isInterestedIn(v2,v0),
   isInterestedIn(v1,v2).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(65),
   isInterestedIn(v0,v2),
   isInterestedIn(v2,v1).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(73),
   isInterestedIn(v1,v2),
   IlivesIn(v2,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(74),
   isInterestedIn(v2,v0),
   IlivesIn(v1,v2).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(77),
   isInterestedIn(v0,v2),
   IlivesIn(v2,v1).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(81),
   isInterestedIn(v0,v1),
   livesIn(v1,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(82),
   isInterestedIn(v1,v0),
   livesIn(v1,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(85),
   isInterestedIn(v1,v2),
   livesIn(v2,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(86),
   isInterestedIn(v2,v0),
   livesIn(v1,v2).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(89),
   isInterestedIn(v0,v2),
   livesIn(v2,v1).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(97),
   IlivesIn(v1,v2),
   IlivesIn(v2,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(98),
   IlivesIn(v2,v0),
   IlivesIn(v1,v2).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(109),
   IlivesIn(v1,v2),
   livesIn(v2,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(110),
   IlivesIn(v2,v0),
   livesIn(v1,v2).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(118),
   livesIn(v1,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(121),
   livesIn(v1,v2),
   livesIn(v2,v0).)_",
	R"_(livesIn(v0,v1) :- 
   Rule(122),
   livesIn(v2,v0),
   livesIn(v1,v2).)_",
};// -- Table: IlivesIn
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_1_IlivesIn = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<0,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_1_IlivesIn;
// -- Table: Rule
std::unique_ptr<t_btree_3__0_1_2__1__7> rel_2_Rule = std::make_unique<t_btree_3__0_1_2__1__7>();
souffle::RelationWrapper<1,t_btree_3__0_1_2__1__7,Tuple<RamDomain,3>,3> wrapper_rel_2_Rule;
// -- Table: isCitizenOf
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_3_isCitizenOf = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<2,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_3_isCitizenOf;
// -- Table: isInterestedIn
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_4_isInterestedIn = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<3,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_4_isInterestedIn;
// -- Table: livesIn
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_5_livesIn = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
souffle::RelationWrapper<4,t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15,Tuple<RamDomain,4>,4> wrapper_rel_5_livesIn;
// -- Table: @delta_livesIn
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_6_delta_livesIn = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
// -- Table: @new_livesIn
std::unique_ptr<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15> rel_7_new_livesIn = std::make_unique<t_btree_4__0_1_3_2__1_0_2_3__1__2__3__15>();
// -- Table: livesIn.@info.1
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_8_livesIn_info_1 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<5,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_8_livesIn_info_1;
// -- Table: livesIn.@info.10
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_9_livesIn_info_10 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<6,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_9_livesIn_info_10;
// -- Table: livesIn.@info.11
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_10_livesIn_info_11 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<7,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_10_livesIn_info_11;
// -- Table: livesIn.@info.12
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_11_livesIn_info_12 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<8,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_11_livesIn_info_12;
// -- Table: livesIn.@info.13
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_12_livesIn_info_13 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<9,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_12_livesIn_info_13;
// -- Table: livesIn.@info.14
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_13_livesIn_info_14 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<10,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_13_livesIn_info_14;
// -- Table: livesIn.@info.15
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_14_livesIn_info_15 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<11,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_14_livesIn_info_15;
// -- Table: livesIn.@info.16
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_15_livesIn_info_16 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<12,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_15_livesIn_info_16;
// -- Table: livesIn.@info.17
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_16_livesIn_info_17 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<13,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_16_livesIn_info_17;
// -- Table: livesIn.@info.18
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_17_livesIn_info_18 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<14,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_17_livesIn_info_18;
// -- Table: livesIn.@info.19
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_18_livesIn_info_19 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<15,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_18_livesIn_info_19;
// -- Table: livesIn.@info.2
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_19_livesIn_info_2 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<16,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_19_livesIn_info_2;
// -- Table: livesIn.@info.20
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_20_livesIn_info_20 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<17,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_20_livesIn_info_20;
// -- Table: livesIn.@info.21
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_21_livesIn_info_21 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<18,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_21_livesIn_info_21;
// -- Table: livesIn.@info.22
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_22_livesIn_info_22 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<19,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_22_livesIn_info_22;
// -- Table: livesIn.@info.23
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_23_livesIn_info_23 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<20,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_23_livesIn_info_23;
// -- Table: livesIn.@info.24
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_24_livesIn_info_24 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<21,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_24_livesIn_info_24;
// -- Table: livesIn.@info.25
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_25_livesIn_info_25 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<22,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_25_livesIn_info_25;
// -- Table: livesIn.@info.26
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_26_livesIn_info_26 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<23,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_26_livesIn_info_26;
// -- Table: livesIn.@info.27
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_27_livesIn_info_27 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<24,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_27_livesIn_info_27;
// -- Table: livesIn.@info.28
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_28_livesIn_info_28 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<25,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_28_livesIn_info_28;
// -- Table: livesIn.@info.29
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_29_livesIn_info_29 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<26,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_29_livesIn_info_29;
// -- Table: livesIn.@info.3
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_30_livesIn_info_3 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<27,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_30_livesIn_info_3;
// -- Table: livesIn.@info.30
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_31_livesIn_info_30 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<28,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_31_livesIn_info_30;
// -- Table: livesIn.@info.31
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_32_livesIn_info_31 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<29,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_32_livesIn_info_31;
// -- Table: livesIn.@info.32
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_33_livesIn_info_32 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<30,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_33_livesIn_info_32;
// -- Table: livesIn.@info.33
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_34_livesIn_info_33 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<31,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_34_livesIn_info_33;
// -- Table: livesIn.@info.34
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_35_livesIn_info_34 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<32,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_35_livesIn_info_34;
// -- Table: livesIn.@info.35
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_36_livesIn_info_35 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<33,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_36_livesIn_info_35;
// -- Table: livesIn.@info.36
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_37_livesIn_info_36 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<34,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_37_livesIn_info_36;
// -- Table: livesIn.@info.37
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_38_livesIn_info_37 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<35,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_38_livesIn_info_37;
// -- Table: livesIn.@info.38
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_39_livesIn_info_38 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<36,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_39_livesIn_info_38;
// -- Table: livesIn.@info.39
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_40_livesIn_info_39 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<37,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_40_livesIn_info_39;
// -- Table: livesIn.@info.4
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_41_livesIn_info_4 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<38,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_41_livesIn_info_4;
// -- Table: livesIn.@info.40
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_42_livesIn_info_40 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<39,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_42_livesIn_info_40;
// -- Table: livesIn.@info.41
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_43_livesIn_info_41 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<40,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_43_livesIn_info_41;
// -- Table: livesIn.@info.42
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_44_livesIn_info_42 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<41,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_44_livesIn_info_42;
// -- Table: livesIn.@info.43
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_45_livesIn_info_43 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<42,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_45_livesIn_info_43;
// -- Table: livesIn.@info.44
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_46_livesIn_info_44 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<43,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_46_livesIn_info_44;
// -- Table: livesIn.@info.45
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_47_livesIn_info_45 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<44,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_47_livesIn_info_45;
// -- Table: livesIn.@info.46
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_48_livesIn_info_46 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<45,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_48_livesIn_info_46;
// -- Table: livesIn.@info.47
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_49_livesIn_info_47 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<46,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_49_livesIn_info_47;
// -- Table: livesIn.@info.48
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_50_livesIn_info_48 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<47,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_50_livesIn_info_48;
// -- Table: livesIn.@info.49
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_51_livesIn_info_49 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<48,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_51_livesIn_info_49;
// -- Table: livesIn.@info.5
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_52_livesIn_info_5 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<49,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_52_livesIn_info_5;
// -- Table: livesIn.@info.50
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_53_livesIn_info_50 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<50,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_53_livesIn_info_50;
// -- Table: livesIn.@info.51
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_54_livesIn_info_51 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<51,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_54_livesIn_info_51;
// -- Table: livesIn.@info.52
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_55_livesIn_info_52 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<52,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_55_livesIn_info_52;
// -- Table: livesIn.@info.6
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_56_livesIn_info_6 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<53,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_56_livesIn_info_6;
// -- Table: livesIn.@info.7
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_57_livesIn_info_7 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<54,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_57_livesIn_info_7;
// -- Table: livesIn.@info.8
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_58_livesIn_info_8 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<55,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_58_livesIn_info_8;
// -- Table: livesIn.@info.9
std::unique_ptr<t_btree_6__0_1_2_3_4_5__63> rel_59_livesIn_info_9 = std::make_unique<t_btree_6__0_1_2_3_4_5__63>();
souffle::RelationWrapper<56,t_btree_6__0_1_2_3_4_5__63,Tuple<RamDomain,6>,6> wrapper_rel_59_livesIn_info_9;
public:
Sf_souffle_small() : 
wrapper_rel_1_IlivesIn(*rel_1_IlivesIn,symTable,"IlivesIn",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_2_Rule(*rel_2_Rule,symTable,"Rule",std::array<const char *,3>{{"i:number","i:number","i:number"}},std::array<const char *,3>{{"n","@rule_number","@level_number"}}),

wrapper_rel_3_isCitizenOf(*rel_3_isCitizenOf,symTable,"isCitizenOf",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_4_isInterestedIn(*rel_4_isInterestedIn,symTable,"isInterestedIn",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_5_livesIn(*rel_5_livesIn,symTable,"livesIn",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_8_livesIn_info_1(*rel_8_livesIn_info_1,symTable,"livesIn.@info.1",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_9_livesIn_info_10(*rel_9_livesIn_info_10,symTable,"livesIn.@info.10",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_10_livesIn_info_11(*rel_10_livesIn_info_11,symTable,"livesIn.@info.11",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_11_livesIn_info_12(*rel_11_livesIn_info_12,symTable,"livesIn.@info.12",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_12_livesIn_info_13(*rel_12_livesIn_info_13,symTable,"livesIn.@info.13",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_13_livesIn_info_14(*rel_13_livesIn_info_14,symTable,"livesIn.@info.14",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_14_livesIn_info_15(*rel_14_livesIn_info_15,symTable,"livesIn.@info.15",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_15_livesIn_info_16(*rel_15_livesIn_info_16,symTable,"livesIn.@info.16",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_16_livesIn_info_17(*rel_16_livesIn_info_17,symTable,"livesIn.@info.17",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_17_livesIn_info_18(*rel_17_livesIn_info_18,symTable,"livesIn.@info.18",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_18_livesIn_info_19(*rel_18_livesIn_info_19,symTable,"livesIn.@info.19",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_19_livesIn_info_2(*rel_19_livesIn_info_2,symTable,"livesIn.@info.2",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_20_livesIn_info_20(*rel_20_livesIn_info_20,symTable,"livesIn.@info.20",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_21_livesIn_info_21(*rel_21_livesIn_info_21,symTable,"livesIn.@info.21",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_22_livesIn_info_22(*rel_22_livesIn_info_22,symTable,"livesIn.@info.22",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_23_livesIn_info_23(*rel_23_livesIn_info_23,symTable,"livesIn.@info.23",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_24_livesIn_info_24(*rel_24_livesIn_info_24,symTable,"livesIn.@info.24",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_25_livesIn_info_25(*rel_25_livesIn_info_25,symTable,"livesIn.@info.25",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_26_livesIn_info_26(*rel_26_livesIn_info_26,symTable,"livesIn.@info.26",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_27_livesIn_info_27(*rel_27_livesIn_info_27,symTable,"livesIn.@info.27",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_28_livesIn_info_28(*rel_28_livesIn_info_28,symTable,"livesIn.@info.28",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_29_livesIn_info_29(*rel_29_livesIn_info_29,symTable,"livesIn.@info.29",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_30_livesIn_info_3(*rel_30_livesIn_info_3,symTable,"livesIn.@info.3",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_31_livesIn_info_30(*rel_31_livesIn_info_30,symTable,"livesIn.@info.30",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_32_livesIn_info_31(*rel_32_livesIn_info_31,symTable,"livesIn.@info.31",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_33_livesIn_info_32(*rel_33_livesIn_info_32,symTable,"livesIn.@info.32",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_34_livesIn_info_33(*rel_34_livesIn_info_33,symTable,"livesIn.@info.33",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_35_livesIn_info_34(*rel_35_livesIn_info_34,symTable,"livesIn.@info.34",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_36_livesIn_info_35(*rel_36_livesIn_info_35,symTable,"livesIn.@info.35",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_37_livesIn_info_36(*rel_37_livesIn_info_36,symTable,"livesIn.@info.36",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_38_livesIn_info_37(*rel_38_livesIn_info_37,symTable,"livesIn.@info.37",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_39_livesIn_info_38(*rel_39_livesIn_info_38,symTable,"livesIn.@info.38",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_40_livesIn_info_39(*rel_40_livesIn_info_39,symTable,"livesIn.@info.39",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_41_livesIn_info_4(*rel_41_livesIn_info_4,symTable,"livesIn.@info.4",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_42_livesIn_info_40(*rel_42_livesIn_info_40,symTable,"livesIn.@info.40",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_43_livesIn_info_41(*rel_43_livesIn_info_41,symTable,"livesIn.@info.41",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_44_livesIn_info_42(*rel_44_livesIn_info_42,symTable,"livesIn.@info.42",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_45_livesIn_info_43(*rel_45_livesIn_info_43,symTable,"livesIn.@info.43",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_46_livesIn_info_44(*rel_46_livesIn_info_44,symTable,"livesIn.@info.44",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_47_livesIn_info_45(*rel_47_livesIn_info_45,symTable,"livesIn.@info.45",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_48_livesIn_info_46(*rel_48_livesIn_info_46,symTable,"livesIn.@info.46",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_49_livesIn_info_47(*rel_49_livesIn_info_47,symTable,"livesIn.@info.47",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_50_livesIn_info_48(*rel_50_livesIn_info_48,symTable,"livesIn.@info.48",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_51_livesIn_info_49(*rel_51_livesIn_info_49,symTable,"livesIn.@info.49",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_52_livesIn_info_5(*rel_52_livesIn_info_5,symTable,"livesIn.@info.5",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_53_livesIn_info_50(*rel_53_livesIn_info_50,symTable,"livesIn.@info.50",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_54_livesIn_info_51(*rel_54_livesIn_info_51,symTable,"livesIn.@info.51",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_55_livesIn_info_52(*rel_55_livesIn_info_52,symTable,"livesIn.@info.52",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_56_livesIn_info_6(*rel_56_livesIn_info_6,symTable,"livesIn.@info.6",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_57_livesIn_info_7(*rel_57_livesIn_info_7,symTable,"livesIn.@info.7",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}),

wrapper_rel_58_livesIn_info_8(*rel_58_livesIn_info_8,symTable,"livesIn.@info.8",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_59_livesIn_info_9(*rel_59_livesIn_info_9,symTable,"livesIn.@info.9",std::array<const char *,6>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,6>{{"clause_num","head_vars","rel_0","rel_1","rel_2","clause_repr"}}){
addRelation("IlivesIn",&wrapper_rel_1_IlivesIn,true,false);
addRelation("Rule",&wrapper_rel_2_Rule,true,false);
addRelation("isCitizenOf",&wrapper_rel_3_isCitizenOf,true,false);
addRelation("isInterestedIn",&wrapper_rel_4_isInterestedIn,true,false);
addRelation("livesIn",&wrapper_rel_5_livesIn,false,true);
addRelation("livesIn.@info.1",&wrapper_rel_8_livesIn_info_1,false,false);
addRelation("livesIn.@info.10",&wrapper_rel_9_livesIn_info_10,false,false);
addRelation("livesIn.@info.11",&wrapper_rel_10_livesIn_info_11,false,false);
addRelation("livesIn.@info.12",&wrapper_rel_11_livesIn_info_12,false,false);
addRelation("livesIn.@info.13",&wrapper_rel_12_livesIn_info_13,false,false);
addRelation("livesIn.@info.14",&wrapper_rel_13_livesIn_info_14,false,false);
addRelation("livesIn.@info.15",&wrapper_rel_14_livesIn_info_15,false,false);
addRelation("livesIn.@info.16",&wrapper_rel_15_livesIn_info_16,false,false);
addRelation("livesIn.@info.17",&wrapper_rel_16_livesIn_info_17,false,false);
addRelation("livesIn.@info.18",&wrapper_rel_17_livesIn_info_18,false,false);
addRelation("livesIn.@info.19",&wrapper_rel_18_livesIn_info_19,false,false);
addRelation("livesIn.@info.2",&wrapper_rel_19_livesIn_info_2,false,false);
addRelation("livesIn.@info.20",&wrapper_rel_20_livesIn_info_20,false,false);
addRelation("livesIn.@info.21",&wrapper_rel_21_livesIn_info_21,false,false);
addRelation("livesIn.@info.22",&wrapper_rel_22_livesIn_info_22,false,false);
addRelation("livesIn.@info.23",&wrapper_rel_23_livesIn_info_23,false,false);
addRelation("livesIn.@info.24",&wrapper_rel_24_livesIn_info_24,false,false);
addRelation("livesIn.@info.25",&wrapper_rel_25_livesIn_info_25,false,false);
addRelation("livesIn.@info.26",&wrapper_rel_26_livesIn_info_26,false,false);
addRelation("livesIn.@info.27",&wrapper_rel_27_livesIn_info_27,false,false);
addRelation("livesIn.@info.28",&wrapper_rel_28_livesIn_info_28,false,false);
addRelation("livesIn.@info.29",&wrapper_rel_29_livesIn_info_29,false,false);
addRelation("livesIn.@info.3",&wrapper_rel_30_livesIn_info_3,false,false);
addRelation("livesIn.@info.30",&wrapper_rel_31_livesIn_info_30,false,false);
addRelation("livesIn.@info.31",&wrapper_rel_32_livesIn_info_31,false,false);
addRelation("livesIn.@info.32",&wrapper_rel_33_livesIn_info_32,false,false);
addRelation("livesIn.@info.33",&wrapper_rel_34_livesIn_info_33,false,false);
addRelation("livesIn.@info.34",&wrapper_rel_35_livesIn_info_34,false,false);
addRelation("livesIn.@info.35",&wrapper_rel_36_livesIn_info_35,false,false);
addRelation("livesIn.@info.36",&wrapper_rel_37_livesIn_info_36,false,false);
addRelation("livesIn.@info.37",&wrapper_rel_38_livesIn_info_37,false,false);
addRelation("livesIn.@info.38",&wrapper_rel_39_livesIn_info_38,false,false);
addRelation("livesIn.@info.39",&wrapper_rel_40_livesIn_info_39,false,false);
addRelation("livesIn.@info.4",&wrapper_rel_41_livesIn_info_4,false,false);
addRelation("livesIn.@info.40",&wrapper_rel_42_livesIn_info_40,false,false);
addRelation("livesIn.@info.41",&wrapper_rel_43_livesIn_info_41,false,false);
addRelation("livesIn.@info.42",&wrapper_rel_44_livesIn_info_42,false,false);
addRelation("livesIn.@info.43",&wrapper_rel_45_livesIn_info_43,false,false);
addRelation("livesIn.@info.44",&wrapper_rel_46_livesIn_info_44,false,false);
addRelation("livesIn.@info.45",&wrapper_rel_47_livesIn_info_45,false,false);
addRelation("livesIn.@info.46",&wrapper_rel_48_livesIn_info_46,false,false);
addRelation("livesIn.@info.47",&wrapper_rel_49_livesIn_info_47,false,false);
addRelation("livesIn.@info.48",&wrapper_rel_50_livesIn_info_48,false,false);
addRelation("livesIn.@info.49",&wrapper_rel_51_livesIn_info_49,false,false);
addRelation("livesIn.@info.5",&wrapper_rel_52_livesIn_info_5,false,false);
addRelation("livesIn.@info.50",&wrapper_rel_53_livesIn_info_50,false,false);
addRelation("livesIn.@info.51",&wrapper_rel_54_livesIn_info_51,false,false);
addRelation("livesIn.@info.52",&wrapper_rel_55_livesIn_info_52,false,false);
addRelation("livesIn.@info.6",&wrapper_rel_56_livesIn_info_6,false,false);
addRelation("livesIn.@info.7",&wrapper_rel_57_livesIn_info_7,false,false);
addRelation("livesIn.@info.8",&wrapper_rel_58_livesIn_info_8,false,false);
addRelation("livesIn.@info.9",&wrapper_rel_59_livesIn_info_9,false,false);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./IlivesIn.facts"},{"name","IlivesIn"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_IlivesIn);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./isCitizenOf.facts"},{"name","isCitizenOf"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_isCitizenOf);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 2 */
/* BEGIN STRATUM 3 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./isInterestedIn.facts"},{"name","isInterestedIn"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_4_isInterestedIn);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,1,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(0,_,@level_num_0),
   isCitizenOf(v0,v1,_,@level_num_1).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [20:1-20:49])_");
if(!(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(0),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(1)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,2,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(1,_,@level_num_0),
   isCitizenOf(v1,v0,_,@level_num_1).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [21:1-21:49])_");
if(!(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(1),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(2)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,3,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(2,_,@level_num_0),
   isInterestedIn(v0,v1,_,@level_num_1).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [22:1-22:52])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(2),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(3)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,4,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(3,_,@level_num_0),
   isInterestedIn(v1,v0,_,@level_num_1).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [23:1-23:52])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(3),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(4)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,6,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(8,_,@level_num_0),
   isCitizenOf(v0,v1,_,@level_num_1).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [25:1-25:70])_");
if(!(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(8),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(6)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,7,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(9,_,@level_num_0),
   isCitizenOf(v0,v1,_,@level_num_1),
   isCitizenOf(v1,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [26:1-26:70])_");
if(!(rel_3_isCitizenOf->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(9),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(7)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,8,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(10,_,@level_num_0),
   isCitizenOf(v1,v0,_,@level_num_1).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [27:1-27:71])_");
if(!(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(10),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(8)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,9,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(11,_,@level_num_0),
   isCitizenOf(v1,v0,_,@level_num_1),
   isCitizenOf(v0,v1,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [28:1-28:71])_");
if(!(rel_3_isCitizenOf->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(11),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(9)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,10,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(12,_,@level_num_0),
   isCitizenOf(v2,v1,_,@level_num_1),
   isCitizenOf(v0,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [29:1-29:71])_");
if(!(rel_3_isCitizenOf->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(12),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_2(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(10)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,11,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(13,_,@level_num_0),
   isCitizenOf(v1,v2,_,@level_num_1),
   isCitizenOf(v2,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [30:1-30:71])_");
if(!(rel_3_isCitizenOf->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(13),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_3_isCitizenOf->equalRange_1(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(11)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,12,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(14,_,@level_num_0),
   isCitizenOf(v2,v0,_,@level_num_1),
   isCitizenOf(v1,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [31:1-31:71])_");
if(!(rel_3_isCitizenOf->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(14),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_2(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(12)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,13,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(17,_,@level_num_0),
   isCitizenOf(v0,v2,_,@level_num_1),
   isCitizenOf(v2,v1,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [32:1-32:71])_");
if(!(rel_3_isCitizenOf->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(17),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_3_isCitizenOf->equalRange_1(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(13)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,14,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(20,_,@level_num_0),
   isCitizenOf(v0,v1,_,@level_num_1),
   isInterestedIn(v0,v1,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [33:1-33:74])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(20),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(14)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,15,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(21,_,@level_num_0),
   isCitizenOf(v0,v1,_,@level_num_1),
   isInterestedIn(v1,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [34:1-34:74])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(21),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(15)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,16,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(22,_,@level_num_0),
   isCitizenOf(v1,v0,_,@level_num_1),
   isInterestedIn(v1,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [35:1-35:74])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(22),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(16)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,17,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(23,_,@level_num_0),
   isCitizenOf(v1,v0,_,@level_num_1),
   isInterestedIn(v0,v1,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [36:1-36:74])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(23),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(17)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,18,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(24,_,@level_num_0),
   isCitizenOf(v2,v1,_,@level_num_1),
   isInterestedIn(v0,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [37:1-37:74])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(24),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_2(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(18)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,19,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(25,_,@level_num_0),
   isCitizenOf(v1,v2,_,@level_num_1),
   isInterestedIn(v2,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [38:1-38:74])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(25),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_4_isInterestedIn->equalRange_1(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(19)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,20,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(26,_,@level_num_0),
   isCitizenOf(v2,v0,_,@level_num_1),
   isInterestedIn(v1,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [39:1-39:74])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(26),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_2(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(20)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,21,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(29,_,@level_num_0),
   isCitizenOf(v0,v2,_,@level_num_1),
   isInterestedIn(v2,v1,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [40:1-40:74])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(29),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_4_isInterestedIn->equalRange_1(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(21)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,22,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(37,_,@level_num_0),
   isCitizenOf(v1,v2,_,@level_num_1),
   IlivesIn(v2,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [41:1-41:68])_");
if(!(rel_1_IlivesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(37),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_1_IlivesIn->equalRange_1(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(22)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,23,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(38,_,@level_num_0),
   isCitizenOf(v2,v0,_,@level_num_1),
   IlivesIn(v1,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [42:1-42:68])_");
if(!(rel_1_IlivesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(38),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_1_IlivesIn->equalRange_2(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(23)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,24,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(41,_,@level_num_0),
   isCitizenOf(v0,v2,_,@level_num_1),
   IlivesIn(v2,v1,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [43:1-43:68])_");
if(!(rel_1_IlivesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(41),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_1_IlivesIn->equalRange_1(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(24)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,30,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(56,_,@level_num_0),
   isInterestedIn(v0,v1,_,@level_num_1).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [49:1-49:77])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(56),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(30)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,31,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(57,_,@level_num_0),
   isInterestedIn(v0,v1,_,@level_num_1),
   isInterestedIn(v1,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [50:1-50:77])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(57),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(31)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,32,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(58,_,@level_num_0),
   isInterestedIn(v1,v0,_,@level_num_1).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [51:1-51:77])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(58),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(32)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,33,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(59,_,@level_num_0),
   isInterestedIn(v1,v0,_,@level_num_1),
   isInterestedIn(v0,v1,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [52:1-52:77])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(59),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(33)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,34,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(60,_,@level_num_0),
   isInterestedIn(v2,v1,_,@level_num_1),
   isInterestedIn(v0,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [53:1-53:77])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(60),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_2(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(34)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,35,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(61,_,@level_num_0),
   isInterestedIn(v1,v2,_,@level_num_1),
   isInterestedIn(v2,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [54:1-54:77])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(61),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_4_isInterestedIn->equalRange_1(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(35)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,36,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(62,_,@level_num_0),
   isInterestedIn(v2,v0,_,@level_num_1),
   isInterestedIn(v1,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [55:1-55:77])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(62),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_2(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(36)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,37,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(65,_,@level_num_0),
   isInterestedIn(v0,v2,_,@level_num_1),
   isInterestedIn(v2,v1,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [56:1-56:77])_");
if(!(rel_4_isInterestedIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(65),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_4_isInterestedIn->equalRange_1(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(37)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,38,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(73,_,@level_num_0),
   isInterestedIn(v1,v2,_,@level_num_1),
   IlivesIn(v2,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [57:1-57:71])_");
if(!(rel_1_IlivesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(73),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_1_IlivesIn->equalRange_1(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(38)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,39,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(74,_,@level_num_0),
   isInterestedIn(v2,v0,_,@level_num_1),
   IlivesIn(v1,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [58:1-58:71])_");
if(!(rel_1_IlivesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(74),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_1_IlivesIn->equalRange_2(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(39)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,40,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(77,_,@level_num_0),
   isInterestedIn(v0,v2,_,@level_num_1),
   IlivesIn(v2,v1,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [59:1-59:71])_");
if(!(rel_1_IlivesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(77),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_1_IlivesIn->equalRange_1(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(40)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,46,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(97,_,@level_num_0),
   IlivesIn(v1,v2,_,@level_num_1),
   IlivesIn(v2,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [65:1-65:65])_");
if(!(rel_1_IlivesIn->empty()) && !(rel_1_IlivesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(97),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_IlivesIn) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_1_IlivesIn->equalRange_1(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(46)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,47,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(98,_,@level_num_0),
   IlivesIn(v2,v0,_,@level_num_1),
   IlivesIn(v1,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [66:1-66:65])_");
if(!(rel_1_IlivesIn->empty()) && !(rel_1_IlivesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(98),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_IlivesIn) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_1_IlivesIn->equalRange_2(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(47)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_5_livesIn->insert(tuple,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
rel_6_delta_livesIn->insertAll(*rel_5_livesIn);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,5,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(7,_,@level_num_0),
   livesIn(v1,v0,_,@level_num_1).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [24:1-24:45])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(7),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_6_delta_livesIn) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({env0[2], env1[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(5)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,25,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(45,_,@level_num_0),
   isCitizenOf(v0,v1,_,@level_num_1),
   livesIn(v1,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [44:1-44:67])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(45),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_6_delta_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(25)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,26,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(46,_,@level_num_0),
   isCitizenOf(v1,v0,_,@level_num_1),
   livesIn(v1,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [45:1-45:67])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(46),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_6_delta_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(26)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,27,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(49,_,@level_num_0),
   isCitizenOf(v1,v2,_,@level_num_1),
   livesIn(v2,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [46:1-46:67])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(49),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_6_delta_livesIn->equalRange_1(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(27)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,28,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(50,_,@level_num_0),
   isCitizenOf(v2,v0,_,@level_num_1),
   livesIn(v1,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [47:1-47:67])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(50),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_6_delta_livesIn->equalRange_2(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(28)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,29,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(53,_,@level_num_0),
   isCitizenOf(v0,v2,_,@level_num_1),
   livesIn(v2,v1,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [48:1-48:67])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(53),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_isCitizenOf) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_6_delta_livesIn->equalRange_1(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(29)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,41,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(81,_,@level_num_0),
   isInterestedIn(v0,v1,_,@level_num_1),
   livesIn(v1,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [60:1-60:70])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(81),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_6_delta_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[0],env1[1],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(41)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,42,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(82,_,@level_num_0),
   isInterestedIn(v1,v0,_,@level_num_1),
   livesIn(v1,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [61:1-61:70])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(82),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_6_delta_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(42)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,43,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(85,_,@level_num_0),
   isInterestedIn(v1,v2,_,@level_num_1),
   livesIn(v2,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [62:1-62:70])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(85),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_6_delta_livesIn->equalRange_1(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(43)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,44,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(86,_,@level_num_0),
   isInterestedIn(v2,v0,_,@level_num_1),
   livesIn(v1,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [63:1-63:70])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(86),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_6_delta_livesIn->equalRange_2(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(44)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,45,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(89,_,@level_num_0),
   isInterestedIn(v0,v2,_,@level_num_1),
   livesIn(v2,v1,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [64:1-64:70])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(89),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_isInterestedIn) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_6_delta_livesIn->equalRange_1(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[0],env2[1],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(RamDomain(45)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,48,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(109,_,@level_num_0),
   IlivesIn(v1,v2,_,@level_num_1),
   livesIn(v2,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [67:1-67:65])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_1_IlivesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(109),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_IlivesIn) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_6_delta_livesIn->equalRange_1(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(48)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,49,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(110,_,@level_num_0),
   IlivesIn(v2,v0,_,@level_num_1),
   livesIn(v1,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [68:1-68:65])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_1_IlivesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(110),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_1_IlivesIn) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_6_delta_livesIn->equalRange_2(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(49)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,50,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(118,_,@level_num_0),
   livesIn(v1,v0,_,@level_num_1).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [69:1-69:64])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(118),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_6_delta_livesIn) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({env0[2], env1[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(50)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,51,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(121,_,@level_num_0),
   livesIn(v1,v2,_,@level_num_1),
   livesIn(v2,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [70:1-70:64])_");
if(!(rel_5_livesIn->empty()) && !(rel_6_delta_livesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(121),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_6_delta_livesIn) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_5_livesIn->equalRange_1(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_6_delta_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[1],0,0}}),READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(51)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,51,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(121,_,@level_num_0),
   livesIn(v1,v2,_,@level_num_1),
   livesIn(v2,v0,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [70:1-70:64])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_5_livesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(121),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_livesIn) {
const Tuple<RamDomain,4> key({{env1[1],0,0,0}});
auto range = rel_6_delta_livesIn->equalRange_1(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env2[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env2[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(51)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,52,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(122,_,@level_num_0),
   livesIn(v2,v0,_,@level_num_1),
   livesIn(v1,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [71:1-71:64])_");
if(!(rel_5_livesIn->empty()) && !(rel_6_delta_livesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(122),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_6_delta_livesIn) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_5_livesIn->equalRange_2(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !(!rel_6_delta_livesIn->equalRange_3(Tuple<RamDomain,4>({{env2[0],env1[0],0,0}}),READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt)).empty()) && !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(52)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(livesIn(v0,v1,52,(max(max(@level_num_0,@level_num_1),@level_num_2)+1)) :- 
   Rule(122,_,@level_num_0),
   livesIn(v2,v0,_,@level_num_1),
   livesIn(v1,v2,_,@level_num_2).
in file /home/johannes/test/popl2020-artifact/prosynth/livesIn/rules.dl [71:1-71:64])_");
if(!(rel_6_delta_livesIn->empty()) && !(rel_5_livesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(122),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
CREATE_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt,rel_6_delta_livesIn->createContext());
CREATE_OP_CONTEXT(rel_7_new_livesIn_op_ctxt,rel_7_new_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_livesIn) {
const Tuple<RamDomain,4> key({{0,env1[0],0,0}});
auto range = rel_6_delta_livesIn->equalRange_2(key,READ_OP_CONTEXT(rel_6_delta_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( !([&]() -> bool {
auto existenceCheck = rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{env1[1],env2[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env2[0]),static_cast<RamDomain>(RamDomain(52)),static_cast<RamDomain>((std::max({std::max({env0[2], env1[3], }), env2[3], })) + (RamDomain(1)))}});
rel_7_new_livesIn->insert(tuple,READ_OP_CONTEXT(rel_7_new_livesIn_op_ctxt));
}
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
if(rel_7_new_livesIn->empty()) break;
rel_5_livesIn->insertAll(*rel_7_new_livesIn);
std::swap(rel_6_delta_livesIn, rel_7_new_livesIn);
rel_7_new_livesIn->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_6_delta_livesIn->purge();
if (!isHintsProfilingEnabled()) rel_7_new_livesIn->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./livesIn.csv"},{"name","livesIn"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_5_livesIn);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.1(1,"v0,v1","Rule","isCitizenOf,v0,v1","livesIn(v0,v1) :- 
   Rule(0),
   isCitizenOf(v0,v1).").
in file  [0:0-0:0])_");
rel_8_livesIn_info_1->insert(RamDomain(1),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(3));
}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.10(10,"v0,v1","Rule","isCitizenOf,v2,v1","isCitizenOf,v0,v2","livesIn(v0,v1) :- 
   Rule(12),
   isCitizenOf(v2,v1),
   isCitizenOf(v0,v2).").
in file  [0:0-0:0])_");
rel_9_livesIn_info_10->insert(RamDomain(10),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(17),RamDomain(18));
}();
/* END STRATUM 6 */
/* BEGIN STRATUM 7 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.11(11,"v0,v1","Rule","isCitizenOf,v1,v2","isCitizenOf,v2,v0","livesIn(v0,v1) :- 
   Rule(13),
   isCitizenOf(v1,v2),
   isCitizenOf(v2,v0).").
in file  [0:0-0:0])_");
rel_10_livesIn_info_11->insert(RamDomain(11),RamDomain(0),RamDomain(1),RamDomain(19),RamDomain(20),RamDomain(21));
}();
/* END STRATUM 7 */
/* BEGIN STRATUM 8 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.12(12,"v0,v1","Rule","isCitizenOf,v2,v0","isCitizenOf,v1,v2","livesIn(v0,v1) :- 
   Rule(14),
   isCitizenOf(v2,v0),
   isCitizenOf(v1,v2).").
in file  [0:0-0:0])_");
rel_11_livesIn_info_12->insert(RamDomain(12),RamDomain(0),RamDomain(1),RamDomain(20),RamDomain(19),RamDomain(22));
}();
/* END STRATUM 8 */
/* BEGIN STRATUM 9 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.13(13,"v0,v1","Rule","isCitizenOf,v0,v2","isCitizenOf,v2,v1","livesIn(v0,v1) :- 
   Rule(17),
   isCitizenOf(v0,v2),
   isCitizenOf(v2,v1).").
in file  [0:0-0:0])_");
rel_12_livesIn_info_13->insert(RamDomain(13),RamDomain(0),RamDomain(1),RamDomain(17),RamDomain(16),RamDomain(23));
}();
/* END STRATUM 9 */
/* BEGIN STRATUM 10 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.14(14,"v0,v1","Rule","isCitizenOf,v0,v1","isInterestedIn,v0,v1","livesIn(v0,v1) :- 
   Rule(20),
   isCitizenOf(v0,v1),
   isInterestedIn(v0,v1).").
in file  [0:0-0:0])_");
rel_13_livesIn_info_14->insert(RamDomain(14),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(6),RamDomain(24));
}();
/* END STRATUM 10 */
/* BEGIN STRATUM 11 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.15(15,"v0,v1","Rule","isCitizenOf,v0,v1","isInterestedIn,v1,v0","livesIn(v0,v1) :- 
   Rule(21),
   isCitizenOf(v0,v1),
   isInterestedIn(v1,v0).").
in file  [0:0-0:0])_");
rel_14_livesIn_info_15->insert(RamDomain(15),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(8),RamDomain(25));
}();
/* END STRATUM 11 */
/* BEGIN STRATUM 12 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.16(16,"v0,v1","Rule","isCitizenOf,v1,v0","isInterestedIn,v1,v0","livesIn(v0,v1) :- 
   Rule(22),
   isCitizenOf(v1,v0),
   isInterestedIn(v1,v0).").
in file  [0:0-0:0])_");
rel_15_livesIn_info_16->insert(RamDomain(16),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(8),RamDomain(26));
}();
/* END STRATUM 12 */
/* BEGIN STRATUM 13 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.17(17,"v0,v1","Rule","isCitizenOf,v1,v0","isInterestedIn,v0,v1","livesIn(v0,v1) :- 
   Rule(23),
   isCitizenOf(v1,v0),
   isInterestedIn(v0,v1).").
in file  [0:0-0:0])_");
rel_16_livesIn_info_17->insert(RamDomain(17),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(6),RamDomain(27));
}();
/* END STRATUM 13 */
/* BEGIN STRATUM 14 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.18(18,"v0,v1","Rule","isCitizenOf,v2,v1","isInterestedIn,v0,v2","livesIn(v0,v1) :- 
   Rule(24),
   isCitizenOf(v2,v1),
   isInterestedIn(v0,v2).").
in file  [0:0-0:0])_");
rel_17_livesIn_info_18->insert(RamDomain(18),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(28),RamDomain(29));
}();
/* END STRATUM 14 */
/* BEGIN STRATUM 15 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.19(19,"v0,v1","Rule","isCitizenOf,v1,v2","isInterestedIn,v2,v0","livesIn(v0,v1) :- 
   Rule(25),
   isCitizenOf(v1,v2),
   isInterestedIn(v2,v0).").
in file  [0:0-0:0])_");
rel_18_livesIn_info_19->insert(RamDomain(19),RamDomain(0),RamDomain(1),RamDomain(19),RamDomain(30),RamDomain(31));
}();
/* END STRATUM 15 */
/* BEGIN STRATUM 16 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.2(2,"v0,v1","Rule","isCitizenOf,v1,v0","livesIn(v0,v1) :- 
   Rule(1),
   isCitizenOf(v1,v0).").
in file  [0:0-0:0])_");
rel_19_livesIn_info_2->insert(RamDomain(2),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(5));
}();
/* END STRATUM 16 */
/* BEGIN STRATUM 17 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.20(20,"v0,v1","Rule","isCitizenOf,v2,v0","isInterestedIn,v1,v2","livesIn(v0,v1) :- 
   Rule(26),
   isCitizenOf(v2,v0),
   isInterestedIn(v1,v2).").
in file  [0:0-0:0])_");
rel_20_livesIn_info_20->insert(RamDomain(20),RamDomain(0),RamDomain(1),RamDomain(20),RamDomain(32),RamDomain(33));
}();
/* END STRATUM 17 */
/* BEGIN STRATUM 18 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.21(21,"v0,v1","Rule","isCitizenOf,v0,v2","isInterestedIn,v2,v1","livesIn(v0,v1) :- 
   Rule(29),
   isCitizenOf(v0,v2),
   isInterestedIn(v2,v1).").
in file  [0:0-0:0])_");
rel_21_livesIn_info_21->insert(RamDomain(21),RamDomain(0),RamDomain(1),RamDomain(17),RamDomain(34),RamDomain(35));
}();
/* END STRATUM 18 */
/* BEGIN STRATUM 19 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.22(22,"v0,v1","Rule","isCitizenOf,v1,v2","IlivesIn,v2,v0","livesIn(v0,v1) :- 
   Rule(37),
   isCitizenOf(v1,v2),
   IlivesIn(v2,v0).").
in file  [0:0-0:0])_");
rel_22_livesIn_info_22->insert(RamDomain(22),RamDomain(0),RamDomain(1),RamDomain(19),RamDomain(36),RamDomain(37));
}();
/* END STRATUM 19 */
/* BEGIN STRATUM 20 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.23(23,"v0,v1","Rule","isCitizenOf,v2,v0","IlivesIn,v1,v2","livesIn(v0,v1) :- 
   Rule(38),
   isCitizenOf(v2,v0),
   IlivesIn(v1,v2).").
in file  [0:0-0:0])_");
rel_23_livesIn_info_23->insert(RamDomain(23),RamDomain(0),RamDomain(1),RamDomain(20),RamDomain(38),RamDomain(39));
}();
/* END STRATUM 20 */
/* BEGIN STRATUM 21 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.24(24,"v0,v1","Rule","isCitizenOf,v0,v2","IlivesIn,v2,v1","livesIn(v0,v1) :- 
   Rule(41),
   isCitizenOf(v0,v2),
   IlivesIn(v2,v1).").
in file  [0:0-0:0])_");
rel_24_livesIn_info_24->insert(RamDomain(24),RamDomain(0),RamDomain(1),RamDomain(17),RamDomain(40),RamDomain(41));
}();
/* END STRATUM 21 */
/* BEGIN STRATUM 22 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.25(25,"v0,v1","Rule","isCitizenOf,v0,v1","livesIn,v1,v0","livesIn(v0,v1) :- 
   Rule(45),
   isCitizenOf(v0,v1),
   livesIn(v1,v0).").
in file  [0:0-0:0])_");
rel_25_livesIn_info_25->insert(RamDomain(25),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(10),RamDomain(42));
}();
/* END STRATUM 22 */
/* BEGIN STRATUM 23 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.26(26,"v0,v1","Rule","isCitizenOf,v1,v0","livesIn,v1,v0","livesIn(v0,v1) :- 
   Rule(46),
   isCitizenOf(v1,v0),
   livesIn(v1,v0).").
in file  [0:0-0:0])_");
rel_26_livesIn_info_26->insert(RamDomain(26),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(10),RamDomain(43));
}();
/* END STRATUM 23 */
/* BEGIN STRATUM 24 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.27(27,"v0,v1","Rule","isCitizenOf,v1,v2","livesIn,v2,v0","livesIn(v0,v1) :- 
   Rule(49),
   isCitizenOf(v1,v2),
   livesIn(v2,v0).").
in file  [0:0-0:0])_");
rel_27_livesIn_info_27->insert(RamDomain(27),RamDomain(0),RamDomain(1),RamDomain(19),RamDomain(44),RamDomain(45));
}();
/* END STRATUM 24 */
/* BEGIN STRATUM 25 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.28(28,"v0,v1","Rule","isCitizenOf,v2,v0","livesIn,v1,v2","livesIn(v0,v1) :- 
   Rule(50),
   isCitizenOf(v2,v0),
   livesIn(v1,v2).").
in file  [0:0-0:0])_");
rel_28_livesIn_info_28->insert(RamDomain(28),RamDomain(0),RamDomain(1),RamDomain(20),RamDomain(46),RamDomain(47));
}();
/* END STRATUM 25 */
/* BEGIN STRATUM 26 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.29(29,"v0,v1","Rule","isCitizenOf,v0,v2","livesIn,v2,v1","livesIn(v0,v1) :- 
   Rule(53),
   isCitizenOf(v0,v2),
   livesIn(v2,v1).").
in file  [0:0-0:0])_");
rel_29_livesIn_info_29->insert(RamDomain(29),RamDomain(0),RamDomain(1),RamDomain(17),RamDomain(48),RamDomain(49));
}();
/* END STRATUM 26 */
/* BEGIN STRATUM 27 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.3(3,"v0,v1","Rule","isInterestedIn,v0,v1","livesIn(v0,v1) :- 
   Rule(2),
   isInterestedIn(v0,v1).").
in file  [0:0-0:0])_");
rel_30_livesIn_info_3->insert(RamDomain(3),RamDomain(0),RamDomain(1),RamDomain(6),RamDomain(7));
}();
/* END STRATUM 27 */
/* BEGIN STRATUM 28 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.30(30,"v0,v1","Rule","isInterestedIn,v0,v1","livesIn(v0,v1) :- 
   Rule(56),
   isInterestedIn(v0,v1).").
in file  [0:0-0:0])_");
rel_31_livesIn_info_30->insert(RamDomain(30),RamDomain(0),RamDomain(1),RamDomain(6),RamDomain(50));
}();
/* END STRATUM 28 */
/* BEGIN STRATUM 29 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.31(31,"v0,v1","Rule","isInterestedIn,v0,v1","isInterestedIn,v1,v0","livesIn(v0,v1) :- 
   Rule(57),
   isInterestedIn(v0,v1),
   isInterestedIn(v1,v0).").
in file  [0:0-0:0])_");
rel_32_livesIn_info_31->insert(RamDomain(31),RamDomain(0),RamDomain(1),RamDomain(6),RamDomain(8),RamDomain(51));
}();
/* END STRATUM 29 */
/* BEGIN STRATUM 30 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.32(32,"v0,v1","Rule","isInterestedIn,v1,v0","livesIn(v0,v1) :- 
   Rule(58),
   isInterestedIn(v1,v0).").
in file  [0:0-0:0])_");
rel_33_livesIn_info_32->insert(RamDomain(32),RamDomain(0),RamDomain(1),RamDomain(8),RamDomain(52));
}();
/* END STRATUM 30 */
/* BEGIN STRATUM 31 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.33(33,"v0,v1","Rule","isInterestedIn,v1,v0","isInterestedIn,v0,v1","livesIn(v0,v1) :- 
   Rule(59),
   isInterestedIn(v1,v0),
   isInterestedIn(v0,v1).").
in file  [0:0-0:0])_");
rel_34_livesIn_info_33->insert(RamDomain(33),RamDomain(0),RamDomain(1),RamDomain(8),RamDomain(6),RamDomain(53));
}();
/* END STRATUM 31 */
/* BEGIN STRATUM 32 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.34(34,"v0,v1","Rule","isInterestedIn,v2,v1","isInterestedIn,v0,v2","livesIn(v0,v1) :- 
   Rule(60),
   isInterestedIn(v2,v1),
   isInterestedIn(v0,v2).").
in file  [0:0-0:0])_");
rel_35_livesIn_info_34->insert(RamDomain(34),RamDomain(0),RamDomain(1),RamDomain(34),RamDomain(28),RamDomain(54));
}();
/* END STRATUM 32 */
/* BEGIN STRATUM 33 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.35(35,"v0,v1","Rule","isInterestedIn,v1,v2","isInterestedIn,v2,v0","livesIn(v0,v1) :- 
   Rule(61),
   isInterestedIn(v1,v2),
   isInterestedIn(v2,v0).").
in file  [0:0-0:0])_");
rel_36_livesIn_info_35->insert(RamDomain(35),RamDomain(0),RamDomain(1),RamDomain(32),RamDomain(30),RamDomain(55));
}();
/* END STRATUM 33 */
/* BEGIN STRATUM 34 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.36(36,"v0,v1","Rule","isInterestedIn,v2,v0","isInterestedIn,v1,v2","livesIn(v0,v1) :- 
   Rule(62),
   isInterestedIn(v2,v0),
   isInterestedIn(v1,v2).").
in file  [0:0-0:0])_");
rel_37_livesIn_info_36->insert(RamDomain(36),RamDomain(0),RamDomain(1),RamDomain(30),RamDomain(32),RamDomain(56));
}();
/* END STRATUM 34 */
/* BEGIN STRATUM 35 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.37(37,"v0,v1","Rule","isInterestedIn,v0,v2","isInterestedIn,v2,v1","livesIn(v0,v1) :- 
   Rule(65),
   isInterestedIn(v0,v2),
   isInterestedIn(v2,v1).").
in file  [0:0-0:0])_");
rel_38_livesIn_info_37->insert(RamDomain(37),RamDomain(0),RamDomain(1),RamDomain(28),RamDomain(34),RamDomain(57));
}();
/* END STRATUM 35 */
/* BEGIN STRATUM 36 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.38(38,"v0,v1","Rule","isInterestedIn,v1,v2","IlivesIn,v2,v0","livesIn(v0,v1) :- 
   Rule(73),
   isInterestedIn(v1,v2),
   IlivesIn(v2,v0).").
in file  [0:0-0:0])_");
rel_39_livesIn_info_38->insert(RamDomain(38),RamDomain(0),RamDomain(1),RamDomain(32),RamDomain(36),RamDomain(58));
}();
/* END STRATUM 36 */
/* BEGIN STRATUM 37 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.39(39,"v0,v1","Rule","isInterestedIn,v2,v0","IlivesIn,v1,v2","livesIn(v0,v1) :- 
   Rule(74),
   isInterestedIn(v2,v0),
   IlivesIn(v1,v2).").
in file  [0:0-0:0])_");
rel_40_livesIn_info_39->insert(RamDomain(39),RamDomain(0),RamDomain(1),RamDomain(30),RamDomain(38),RamDomain(59));
}();
/* END STRATUM 37 */
/* BEGIN STRATUM 38 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.4(4,"v0,v1","Rule","isInterestedIn,v1,v0","livesIn(v0,v1) :- 
   Rule(3),
   isInterestedIn(v1,v0).").
in file  [0:0-0:0])_");
rel_41_livesIn_info_4->insert(RamDomain(4),RamDomain(0),RamDomain(1),RamDomain(8),RamDomain(9));
}();
/* END STRATUM 38 */
/* BEGIN STRATUM 39 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.40(40,"v0,v1","Rule","isInterestedIn,v0,v2","IlivesIn,v2,v1","livesIn(v0,v1) :- 
   Rule(77),
   isInterestedIn(v0,v2),
   IlivesIn(v2,v1).").
in file  [0:0-0:0])_");
rel_42_livesIn_info_40->insert(RamDomain(40),RamDomain(0),RamDomain(1),RamDomain(28),RamDomain(40),RamDomain(60));
}();
/* END STRATUM 39 */
/* BEGIN STRATUM 40 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.41(41,"v0,v1","Rule","isInterestedIn,v0,v1","livesIn,v1,v0","livesIn(v0,v1) :- 
   Rule(81),
   isInterestedIn(v0,v1),
   livesIn(v1,v0).").
in file  [0:0-0:0])_");
rel_43_livesIn_info_41->insert(RamDomain(41),RamDomain(0),RamDomain(1),RamDomain(6),RamDomain(10),RamDomain(61));
}();
/* END STRATUM 40 */
/* BEGIN STRATUM 41 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.42(42,"v0,v1","Rule","isInterestedIn,v1,v0","livesIn,v1,v0","livesIn(v0,v1) :- 
   Rule(82),
   isInterestedIn(v1,v0),
   livesIn(v1,v0).").
in file  [0:0-0:0])_");
rel_44_livesIn_info_42->insert(RamDomain(42),RamDomain(0),RamDomain(1),RamDomain(8),RamDomain(10),RamDomain(62));
}();
/* END STRATUM 41 */
/* BEGIN STRATUM 42 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.43(43,"v0,v1","Rule","isInterestedIn,v1,v2","livesIn,v2,v0","livesIn(v0,v1) :- 
   Rule(85),
   isInterestedIn(v1,v2),
   livesIn(v2,v0).").
in file  [0:0-0:0])_");
rel_45_livesIn_info_43->insert(RamDomain(43),RamDomain(0),RamDomain(1),RamDomain(32),RamDomain(44),RamDomain(63));
}();
/* END STRATUM 42 */
/* BEGIN STRATUM 43 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.44(44,"v0,v1","Rule","isInterestedIn,v2,v0","livesIn,v1,v2","livesIn(v0,v1) :- 
   Rule(86),
   isInterestedIn(v2,v0),
   livesIn(v1,v2).").
in file  [0:0-0:0])_");
rel_46_livesIn_info_44->insert(RamDomain(44),RamDomain(0),RamDomain(1),RamDomain(30),RamDomain(46),RamDomain(64));
}();
/* END STRATUM 43 */
/* BEGIN STRATUM 44 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.45(45,"v0,v1","Rule","isInterestedIn,v0,v2","livesIn,v2,v1","livesIn(v0,v1) :- 
   Rule(89),
   isInterestedIn(v0,v2),
   livesIn(v2,v1).").
in file  [0:0-0:0])_");
rel_47_livesIn_info_45->insert(RamDomain(45),RamDomain(0),RamDomain(1),RamDomain(28),RamDomain(48),RamDomain(65));
}();
/* END STRATUM 44 */
/* BEGIN STRATUM 45 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.46(46,"v0,v1","Rule","IlivesIn,v1,v2","IlivesIn,v2,v0","livesIn(v0,v1) :- 
   Rule(97),
   IlivesIn(v1,v2),
   IlivesIn(v2,v0).").
in file  [0:0-0:0])_");
rel_48_livesIn_info_46->insert(RamDomain(46),RamDomain(0),RamDomain(1),RamDomain(38),RamDomain(36),RamDomain(66));
}();
/* END STRATUM 45 */
/* BEGIN STRATUM 46 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.47(47,"v0,v1","Rule","IlivesIn,v2,v0","IlivesIn,v1,v2","livesIn(v0,v1) :- 
   Rule(98),
   IlivesIn(v2,v0),
   IlivesIn(v1,v2).").
in file  [0:0-0:0])_");
rel_49_livesIn_info_47->insert(RamDomain(47),RamDomain(0),RamDomain(1),RamDomain(36),RamDomain(38),RamDomain(67));
}();
/* END STRATUM 46 */
/* BEGIN STRATUM 47 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.48(48,"v0,v1","Rule","IlivesIn,v1,v2","livesIn,v2,v0","livesIn(v0,v1) :- 
   Rule(109),
   IlivesIn(v1,v2),
   livesIn(v2,v0).").
in file  [0:0-0:0])_");
rel_50_livesIn_info_48->insert(RamDomain(48),RamDomain(0),RamDomain(1),RamDomain(38),RamDomain(44),RamDomain(68));
}();
/* END STRATUM 47 */
/* BEGIN STRATUM 48 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.49(49,"v0,v1","Rule","IlivesIn,v2,v0","livesIn,v1,v2","livesIn(v0,v1) :- 
   Rule(110),
   IlivesIn(v2,v0),
   livesIn(v1,v2).").
in file  [0:0-0:0])_");
rel_51_livesIn_info_49->insert(RamDomain(49),RamDomain(0),RamDomain(1),RamDomain(36),RamDomain(46),RamDomain(69));
}();
/* END STRATUM 48 */
/* BEGIN STRATUM 49 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.5(5,"v0,v1","Rule","livesIn,v1,v0","livesIn(v0,v1) :- 
   Rule(7),
   livesIn(v1,v0).").
in file  [0:0-0:0])_");
rel_52_livesIn_info_5->insert(RamDomain(5),RamDomain(0),RamDomain(1),RamDomain(10),RamDomain(11));
}();
/* END STRATUM 49 */
/* BEGIN STRATUM 50 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.50(50,"v0,v1","Rule","livesIn,v1,v0","livesIn(v0,v1) :- 
   Rule(118),
   livesIn(v1,v0).").
in file  [0:0-0:0])_");
rel_53_livesIn_info_50->insert(RamDomain(50),RamDomain(0),RamDomain(1),RamDomain(10),RamDomain(70));
}();
/* END STRATUM 50 */
/* BEGIN STRATUM 51 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.51(51,"v0,v1","Rule","livesIn,v1,v2","livesIn,v2,v0","livesIn(v0,v1) :- 
   Rule(121),
   livesIn(v1,v2),
   livesIn(v2,v0).").
in file  [0:0-0:0])_");
rel_54_livesIn_info_51->insert(RamDomain(51),RamDomain(0),RamDomain(1),RamDomain(46),RamDomain(44),RamDomain(71));
}();
/* END STRATUM 51 */
/* BEGIN STRATUM 52 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.52(52,"v0,v1","Rule","livesIn,v2,v0","livesIn,v1,v2","livesIn(v0,v1) :- 
   Rule(122),
   livesIn(v2,v0),
   livesIn(v1,v2).").
in file  [0:0-0:0])_");
rel_55_livesIn_info_52->insert(RamDomain(52),RamDomain(0),RamDomain(1),RamDomain(44),RamDomain(46),RamDomain(72));
}();
/* END STRATUM 52 */
/* BEGIN STRATUM 53 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.6(6,"v0,v1","Rule","isCitizenOf,v0,v1","livesIn(v0,v1) :- 
   Rule(8),
   isCitizenOf(v0,v1).").
in file  [0:0-0:0])_");
rel_56_livesIn_info_6->insert(RamDomain(6),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(12));
}();
/* END STRATUM 53 */
/* BEGIN STRATUM 54 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.7(7,"v0,v1","Rule","isCitizenOf,v0,v1","isCitizenOf,v1,v0","livesIn(v0,v1) :- 
   Rule(9),
   isCitizenOf(v0,v1),
   isCitizenOf(v1,v0).").
in file  [0:0-0:0])_");
rel_57_livesIn_info_7->insert(RamDomain(7),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(4),RamDomain(13));
}();
/* END STRATUM 54 */
/* BEGIN STRATUM 55 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.8(8,"v0,v1","Rule","isCitizenOf,v1,v0","livesIn(v0,v1) :- 
   Rule(10),
   isCitizenOf(v1,v0).").
in file  [0:0-0:0])_");
rel_58_livesIn_info_8->insert(RamDomain(8),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(14));
}();
/* END STRATUM 55 */
/* BEGIN STRATUM 56 */
[&]() {
SignalHandler::instance()->setMsg(R"_(livesIn.@info.9(9,"v0,v1","Rule","isCitizenOf,v1,v0","isCitizenOf,v0,v1","livesIn(v0,v1) :- 
   Rule(11),
   isCitizenOf(v1,v0),
   isCitizenOf(v0,v1).").
in file  [0:0-0:0])_");
rel_59_livesIn_info_9->insert(RamDomain(9),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(2),RamDomain(15));
}();
/* END STRATUM 56 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_IlivesIn:\n";
rel_1_IlivesIn->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_Rule:\n";
rel_2_Rule->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_isCitizenOf:\n";
rel_3_isCitizenOf->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_isInterestedIn:\n";
rel_4_isInterestedIn->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_livesIn:\n";
rel_5_livesIn->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_delta_livesIn:\n";
rel_6_delta_livesIn->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_new_livesIn:\n";
rel_7_new_livesIn->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_livesIn_info_1:\n";
rel_8_livesIn_info_1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_livesIn_info_10:\n";
rel_9_livesIn_info_10->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_livesIn_info_11:\n";
rel_10_livesIn_info_11->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_livesIn_info_12:\n";
rel_11_livesIn_info_12->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_livesIn_info_13:\n";
rel_12_livesIn_info_13->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_13_livesIn_info_14:\n";
rel_13_livesIn_info_14->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_14_livesIn_info_15:\n";
rel_14_livesIn_info_15->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_15_livesIn_info_16:\n";
rel_15_livesIn_info_16->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_16_livesIn_info_17:\n";
rel_16_livesIn_info_17->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_17_livesIn_info_18:\n";
rel_17_livesIn_info_18->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_18_livesIn_info_19:\n";
rel_18_livesIn_info_19->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_19_livesIn_info_2:\n";
rel_19_livesIn_info_2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_20_livesIn_info_20:\n";
rel_20_livesIn_info_20->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_21_livesIn_info_21:\n";
rel_21_livesIn_info_21->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_22_livesIn_info_22:\n";
rel_22_livesIn_info_22->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_23_livesIn_info_23:\n";
rel_23_livesIn_info_23->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_24_livesIn_info_24:\n";
rel_24_livesIn_info_24->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_25_livesIn_info_25:\n";
rel_25_livesIn_info_25->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_26_livesIn_info_26:\n";
rel_26_livesIn_info_26->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_27_livesIn_info_27:\n";
rel_27_livesIn_info_27->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_28_livesIn_info_28:\n";
rel_28_livesIn_info_28->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_29_livesIn_info_29:\n";
rel_29_livesIn_info_29->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_30_livesIn_info_3:\n";
rel_30_livesIn_info_3->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_31_livesIn_info_30:\n";
rel_31_livesIn_info_30->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_32_livesIn_info_31:\n";
rel_32_livesIn_info_31->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_33_livesIn_info_32:\n";
rel_33_livesIn_info_32->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_34_livesIn_info_33:\n";
rel_34_livesIn_info_33->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_35_livesIn_info_34:\n";
rel_35_livesIn_info_34->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_36_livesIn_info_35:\n";
rel_36_livesIn_info_35->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_37_livesIn_info_36:\n";
rel_37_livesIn_info_36->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_38_livesIn_info_37:\n";
rel_38_livesIn_info_37->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_39_livesIn_info_38:\n";
rel_39_livesIn_info_38->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_40_livesIn_info_39:\n";
rel_40_livesIn_info_39->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_41_livesIn_info_4:\n";
rel_41_livesIn_info_4->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_42_livesIn_info_40:\n";
rel_42_livesIn_info_40->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_43_livesIn_info_41:\n";
rel_43_livesIn_info_41->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_44_livesIn_info_42:\n";
rel_44_livesIn_info_42->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_45_livesIn_info_43:\n";
rel_45_livesIn_info_43->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_46_livesIn_info_44:\n";
rel_46_livesIn_info_44->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_47_livesIn_info_45:\n";
rel_47_livesIn_info_45->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_48_livesIn_info_46:\n";
rel_48_livesIn_info_46->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_49_livesIn_info_47:\n";
rel_49_livesIn_info_47->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_50_livesIn_info_48:\n";
rel_50_livesIn_info_48->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_51_livesIn_info_49:\n";
rel_51_livesIn_info_49->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_52_livesIn_info_5:\n";
rel_52_livesIn_info_5->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_53_livesIn_info_50:\n";
rel_53_livesIn_info_50->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_54_livesIn_info_51:\n";
rel_54_livesIn_info_51->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_55_livesIn_info_52:\n";
rel_55_livesIn_info_52->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_56_livesIn_info_6:\n";
rel_56_livesIn_info_6->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_57_livesIn_info_7:\n";
rel_57_livesIn_info_7->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_58_livesIn_info_8:\n";
rel_58_livesIn_info_8->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_59_livesIn_info_9:\n";
rel_59_livesIn_info_9->printHintStatistics(std::cout,"  ");
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./livesIn.csv"},{"name","livesIn"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_5_livesIn);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./IlivesIn.facts"},{"name","IlivesIn"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_IlivesIn);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Rule.facts"},{"name","Rule"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->readAll(*rel_2_Rule);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./isCitizenOf.facts"},{"name","isCitizenOf"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_isCitizenOf);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./isInterestedIn.facts"},{"name","isInterestedIn"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_4_isInterestedIn);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
public:
void dumpInputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_1_IlivesIn");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_1_IlivesIn);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_2_Rule");
IOSystem::getInstance().getWriter(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->writeAll(*rel_2_Rule);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_isCitizenOf");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_3_isCitizenOf);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_4_isInterestedIn");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_isInterestedIn);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_5_livesIn");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_5_livesIn);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
SymbolTable& getSymbolTable() override {
return symTable;
}
void executeSubroutine(std::string name, const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) override {
if (name == "livesIn_10_negation_subproof") {
subproof_0(args, ret, err);
}
if (name == "livesIn_10_subproof") {
subproof_1(args, ret, err);
}
if (name == "livesIn_11_negation_subproof") {
subproof_2(args, ret, err);
}
if (name == "livesIn_11_subproof") {
subproof_3(args, ret, err);
}
if (name == "livesIn_12_negation_subproof") {
subproof_4(args, ret, err);
}
if (name == "livesIn_12_subproof") {
subproof_5(args, ret, err);
}
if (name == "livesIn_13_negation_subproof") {
subproof_6(args, ret, err);
}
if (name == "livesIn_13_subproof") {
subproof_7(args, ret, err);
}
if (name == "livesIn_14_negation_subproof") {
subproof_8(args, ret, err);
}
if (name == "livesIn_14_subproof") {
subproof_9(args, ret, err);
}
if (name == "livesIn_15_negation_subproof") {
subproof_10(args, ret, err);
}
if (name == "livesIn_15_subproof") {
subproof_11(args, ret, err);
}
if (name == "livesIn_16_negation_subproof") {
subproof_12(args, ret, err);
}
if (name == "livesIn_16_subproof") {
subproof_13(args, ret, err);
}
if (name == "livesIn_17_negation_subproof") {
subproof_14(args, ret, err);
}
if (name == "livesIn_17_subproof") {
subproof_15(args, ret, err);
}
if (name == "livesIn_18_negation_subproof") {
subproof_16(args, ret, err);
}
if (name == "livesIn_18_subproof") {
subproof_17(args, ret, err);
}
if (name == "livesIn_19_negation_subproof") {
subproof_18(args, ret, err);
}
if (name == "livesIn_19_subproof") {
subproof_19(args, ret, err);
}
if (name == "livesIn_1_negation_subproof") {
subproof_20(args, ret, err);
}
if (name == "livesIn_1_subproof") {
subproof_21(args, ret, err);
}
if (name == "livesIn_20_negation_subproof") {
subproof_22(args, ret, err);
}
if (name == "livesIn_20_subproof") {
subproof_23(args, ret, err);
}
if (name == "livesIn_21_negation_subproof") {
subproof_24(args, ret, err);
}
if (name == "livesIn_21_subproof") {
subproof_25(args, ret, err);
}
if (name == "livesIn_22_negation_subproof") {
subproof_26(args, ret, err);
}
if (name == "livesIn_22_subproof") {
subproof_27(args, ret, err);
}
if (name == "livesIn_23_negation_subproof") {
subproof_28(args, ret, err);
}
if (name == "livesIn_23_subproof") {
subproof_29(args, ret, err);
}
if (name == "livesIn_24_negation_subproof") {
subproof_30(args, ret, err);
}
if (name == "livesIn_24_subproof") {
subproof_31(args, ret, err);
}
if (name == "livesIn_25_negation_subproof") {
subproof_32(args, ret, err);
}
if (name == "livesIn_25_subproof") {
subproof_33(args, ret, err);
}
if (name == "livesIn_26_negation_subproof") {
subproof_34(args, ret, err);
}
if (name == "livesIn_26_subproof") {
subproof_35(args, ret, err);
}
if (name == "livesIn_27_negation_subproof") {
subproof_36(args, ret, err);
}
if (name == "livesIn_27_subproof") {
subproof_37(args, ret, err);
}
if (name == "livesIn_28_negation_subproof") {
subproof_38(args, ret, err);
}
if (name == "livesIn_28_subproof") {
subproof_39(args, ret, err);
}
if (name == "livesIn_29_negation_subproof") {
subproof_40(args, ret, err);
}
if (name == "livesIn_29_subproof") {
subproof_41(args, ret, err);
}
if (name == "livesIn_2_negation_subproof") {
subproof_42(args, ret, err);
}
if (name == "livesIn_2_subproof") {
subproof_43(args, ret, err);
}
if (name == "livesIn_30_negation_subproof") {
subproof_44(args, ret, err);
}
if (name == "livesIn_30_subproof") {
subproof_45(args, ret, err);
}
if (name == "livesIn_31_negation_subproof") {
subproof_46(args, ret, err);
}
if (name == "livesIn_31_subproof") {
subproof_47(args, ret, err);
}
if (name == "livesIn_32_negation_subproof") {
subproof_48(args, ret, err);
}
if (name == "livesIn_32_subproof") {
subproof_49(args, ret, err);
}
if (name == "livesIn_33_negation_subproof") {
subproof_50(args, ret, err);
}
if (name == "livesIn_33_subproof") {
subproof_51(args, ret, err);
}
if (name == "livesIn_34_negation_subproof") {
subproof_52(args, ret, err);
}
if (name == "livesIn_34_subproof") {
subproof_53(args, ret, err);
}
if (name == "livesIn_35_negation_subproof") {
subproof_54(args, ret, err);
}
if (name == "livesIn_35_subproof") {
subproof_55(args, ret, err);
}
if (name == "livesIn_36_negation_subproof") {
subproof_56(args, ret, err);
}
if (name == "livesIn_36_subproof") {
subproof_57(args, ret, err);
}
if (name == "livesIn_37_negation_subproof") {
subproof_58(args, ret, err);
}
if (name == "livesIn_37_subproof") {
subproof_59(args, ret, err);
}
if (name == "livesIn_38_negation_subproof") {
subproof_60(args, ret, err);
}
if (name == "livesIn_38_subproof") {
subproof_61(args, ret, err);
}
if (name == "livesIn_39_negation_subproof") {
subproof_62(args, ret, err);
}
if (name == "livesIn_39_subproof") {
subproof_63(args, ret, err);
}
if (name == "livesIn_3_negation_subproof") {
subproof_64(args, ret, err);
}
if (name == "livesIn_3_subproof") {
subproof_65(args, ret, err);
}
if (name == "livesIn_40_negation_subproof") {
subproof_66(args, ret, err);
}
if (name == "livesIn_40_subproof") {
subproof_67(args, ret, err);
}
if (name == "livesIn_41_negation_subproof") {
subproof_68(args, ret, err);
}
if (name == "livesIn_41_subproof") {
subproof_69(args, ret, err);
}
if (name == "livesIn_42_negation_subproof") {
subproof_70(args, ret, err);
}
if (name == "livesIn_42_subproof") {
subproof_71(args, ret, err);
}
if (name == "livesIn_43_negation_subproof") {
subproof_72(args, ret, err);
}
if (name == "livesIn_43_subproof") {
subproof_73(args, ret, err);
}
if (name == "livesIn_44_negation_subproof") {
subproof_74(args, ret, err);
}
if (name == "livesIn_44_subproof") {
subproof_75(args, ret, err);
}
if (name == "livesIn_45_negation_subproof") {
subproof_76(args, ret, err);
}
if (name == "livesIn_45_subproof") {
subproof_77(args, ret, err);
}
if (name == "livesIn_46_negation_subproof") {
subproof_78(args, ret, err);
}
if (name == "livesIn_46_subproof") {
subproof_79(args, ret, err);
}
if (name == "livesIn_47_negation_subproof") {
subproof_80(args, ret, err);
}
if (name == "livesIn_47_subproof") {
subproof_81(args, ret, err);
}
if (name == "livesIn_48_negation_subproof") {
subproof_82(args, ret, err);
}
if (name == "livesIn_48_subproof") {
subproof_83(args, ret, err);
}
if (name == "livesIn_49_negation_subproof") {
subproof_84(args, ret, err);
}
if (name == "livesIn_49_subproof") {
subproof_85(args, ret, err);
}
if (name == "livesIn_4_negation_subproof") {
subproof_86(args, ret, err);
}
if (name == "livesIn_4_subproof") {
subproof_87(args, ret, err);
}
if (name == "livesIn_50_negation_subproof") {
subproof_88(args, ret, err);
}
if (name == "livesIn_50_subproof") {
subproof_89(args, ret, err);
}
if (name == "livesIn_51_negation_subproof") {
subproof_90(args, ret, err);
}
if (name == "livesIn_51_subproof") {
subproof_91(args, ret, err);
}
if (name == "livesIn_52_negation_subproof") {
subproof_92(args, ret, err);
}
if (name == "livesIn_52_subproof") {
subproof_93(args, ret, err);
}
if (name == "livesIn_5_negation_subproof") {
subproof_94(args, ret, err);
}
if (name == "livesIn_5_subproof") {
subproof_95(args, ret, err);
}
if (name == "livesIn_6_negation_subproof") {
subproof_96(args, ret, err);
}
if (name == "livesIn_6_subproof") {
subproof_97(args, ret, err);
}
if (name == "livesIn_7_negation_subproof") {
subproof_98(args, ret, err);
}
if (name == "livesIn_7_subproof") {
subproof_99(args, ret, err);
}
if (name == "livesIn_8_negation_subproof") {
subproof_100(args, ret, err);
}
if (name == "livesIn_8_subproof") {
subproof_101(args, ret, err);
}
if (name == "livesIn_9_negation_subproof") {
subproof_102(args, ret, err);
}
if (name == "livesIn_9_subproof") {
subproof_103(args, ret, err);
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
void subproof_1(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_isCitizenOf->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(12),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_isCitizenOf->equalRange_2(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
if(!(rel_3_isCitizenOf->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(13),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_isCitizenOf->equalRange_1(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
if(!(rel_3_isCitizenOf->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(14),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_2(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
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
void subproof_6(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
if(!(rel_3_isCitizenOf->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(17),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_isCitizenOf->equalRange_1(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
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
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(20),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(20));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
void subproof_9(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(20),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(20));
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
void subproof_10(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(21),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(21));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
void subproof_11(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(21),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(21));
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
void subproof_12(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(22),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(22));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(22),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(22));
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
void subproof_14(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(23),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(23));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
void subproof_15(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(23),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(23));
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
void subproof_16(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(24),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(24));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(24),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_3_isCitizenOf->equalRange_2(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(24));
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
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(25),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(25));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(25),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_isCitizenOf->equalRange_1(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(25));
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
if(!(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(0),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
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
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(26),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(26));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(26),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_2(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(26));
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
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(29),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(29));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
if(!(rel_4_isInterestedIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(29),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_isCitizenOf->equalRange_1(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(29));
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
void subproof_26(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
if(!rel_1_IlivesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt)).empty()) {
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
void subproof_27(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_IlivesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(37),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_isCitizenOf->equalRange_1(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_1_IlivesIn->equalRange_3(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
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
void subproof_28(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
if(!rel_1_IlivesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt)).empty()) {
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
void subproof_29(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_IlivesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(38),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_2(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_1_IlivesIn->equalRange_3(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
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
void subproof_30(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
if(!rel_1_IlivesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt)).empty()) {
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
void subproof_31(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_IlivesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(41),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_isCitizenOf->equalRange_1(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_1_IlivesIn->equalRange_3(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
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
void subproof_32(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(45),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(45));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_33(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(45),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(45));
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
void subproof_34(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(46),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(46));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_35(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(46),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(46));
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
void subproof_36(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(49),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(49));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_37(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(49),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_3_isCitizenOf->equalRange_1(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(49));
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
void subproof_38(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(50),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(50));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_39(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(50),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_2(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(50));
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
void subproof_40(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(53),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(53));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_41(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(53),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_3_isCitizenOf->equalRange_1(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(53));
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
if(!(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(1),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
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
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(56),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(56));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
void subproof_45(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(56),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(56));
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
void subproof_46(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(57),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(57));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
void subproof_47(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_isInterestedIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(57),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(57));
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
void subproof_48(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(58),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(58));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
void subproof_49(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(58),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(58));
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
void subproof_50(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(59),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(59));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
void subproof_51(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_isInterestedIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(59),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(59));
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
void subproof_52(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(60),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(60));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
if(!(rel_4_isInterestedIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(60),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[1],0,0}});
auto range = rel_4_isInterestedIn->equalRange_2(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(60));
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
void subproof_54(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(61),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(61));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
void subproof_55(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_isInterestedIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(61),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_4_isInterestedIn->equalRange_1(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(61));
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
void subproof_56(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(62),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(62));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
void subproof_57(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_isInterestedIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(62),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_2(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(62));
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
void subproof_58(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(65),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(65));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
void subproof_59(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_isInterestedIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(65),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_4_isInterestedIn->equalRange_1(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(65));
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
void subproof_60(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
if(!rel_1_IlivesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt)).empty()) {
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
void subproof_61(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_IlivesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(73),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_4_isInterestedIn->equalRange_1(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_1_IlivesIn->equalRange_3(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
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
void subproof_62(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
if(!rel_1_IlivesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt)).empty()) {
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
void subproof_63(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_IlivesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(74),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_2(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_1_IlivesIn->equalRange_3(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
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
void subproof_64(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(2),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(2));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
void subproof_65(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(2),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(2));
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
void subproof_66(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
if(!rel_1_IlivesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt)).empty()) {
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
void subproof_67(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_IlivesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(77),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_4_isInterestedIn->equalRange_1(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_1_IlivesIn->equalRange_3(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
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
void subproof_68(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(81),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(81));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_69(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(81),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(81));
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
void subproof_70(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_71(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(82),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[0],env1[1],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
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
void subproof_72(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_73(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(85),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_4_isInterestedIn->equalRange_1(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
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
void subproof_74(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_75(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(86),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_2(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
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
void subproof_76(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[2],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[1],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_77(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(89),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],0,0,0}});
auto range = rel_4_isInterestedIn->equalRange_1(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[1],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
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
void subproof_78(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
if(!rel_1_IlivesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
if(!rel_1_IlivesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt)).empty()) {
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
void subproof_79(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_IlivesIn->empty()) && !(rel_1_IlivesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(97),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_1_IlivesIn->equalRange_1(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_1_IlivesIn->equalRange_3(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
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
void subproof_80(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(98),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(98));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
if(!rel_1_IlivesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
if(!rel_1_IlivesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt)).empty()) {
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
void subproof_81(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_1_IlivesIn->empty()) && !(rel_1_IlivesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(98),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_1_IlivesIn->equalRange_2(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_1_IlivesIn->equalRange_3(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(98));
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
void subproof_82(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
if(!rel_1_IlivesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_83(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_1_IlivesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(109),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_1_IlivesIn->equalRange_1(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
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
void subproof_84(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
if(!rel_1_IlivesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_85(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_1_IlivesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(110),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_IlivesIn_op_ctxt,rel_1_IlivesIn->createContext());
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_1_IlivesIn->equalRange_2(key,READ_OP_CONTEXT(rel_1_IlivesIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
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
void subproof_86(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(3),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(3));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
if(!rel_4_isInterestedIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt)).empty()) {
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
void subproof_87(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_isInterestedIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(3),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt,rel_4_isInterestedIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_4_isInterestedIn->equalRange_3(key,READ_OP_CONTEXT(rel_4_isInterestedIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(3));
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
void subproof_88(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_89(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(118),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_90(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_91(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_5_livesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(121),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],0,0,0}});
auto range = rel_5_livesIn->equalRange_1(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],(args)[0],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
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
void subproof_92(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
if(!rel_2_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(122),0,0}}),READ_OP_CONTEXT(rel_2_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(122));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[2],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[2],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_93(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_5_livesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(122),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{0,(args)[0],0,0}});
auto range = rel_5_livesIn->equalRange_2(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],env1[0],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env2 : range) {
if( ((env2[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(122));
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
void subproof_94(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
if(!rel_5_livesIn->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_livesIn_op_ctxt)).empty()) {
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
void subproof_95(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_livesIn->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(7),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_livesIn_op_ctxt,rel_5_livesIn->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_5_livesIn->equalRange_3(key,READ_OP_CONTEXT(rel_5_livesIn_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_96(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
void subproof_97(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(8),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
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
void subproof_98(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
void subproof_99(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_isCitizenOf->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(9),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
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
void subproof_100(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
void subproof_101(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(10),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_102(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
if(!rel_3_isCitizenOf->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt)).empty()) {
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
if(!(rel_3_isCitizenOf->empty()) && !(rel_3_isCitizenOf->empty()) && !(rel_2_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(11),0,0}});
auto range = rel_2_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_2_Rule_op_ctxt,rel_2_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt,rel_3_isCitizenOf->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{env1[1],env1[0],0,0}});
auto range = rel_3_isCitizenOf->equalRange_3(key,READ_OP_CONTEXT(rel_3_isCitizenOf_op_ctxt));
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
2,
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
