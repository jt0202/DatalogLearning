
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
	R"_(islocatedin,v0,v1)_",
	R"_(inv_0(v0,v1) :- 
   Rule(0),
   islocatedin(v0,v1).)_",
	R"_(islocatedin,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(1),
   islocatedin(v1,v0).)_",
	R"_(directed,v0,v1)_",
	R"_(inv_0(v0,v1) :- 
   Rule(2),
   directed(v0,v1).)_",
	R"_(directed,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(3),
   directed(v1,v0).)_",
	R"_(haschild,v0,v1)_",
	R"_(inv_0(v0,v1) :- 
   Rule(4),
   haschild(v0,v1).)_",
	R"_(haschild,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(5),
   haschild(v1,v0).)_",
	R"_(diedin,v0,v1)_",
	R"_(inv_0(v0,v1) :- 
   Rule(6),
   diedin(v0,v1).)_",
	R"_(diedin,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(7),
   diedin(v1,v0).)_",
	R"_(created,v0,v1)_",
	R"_(inv_0(v0,v1) :- 
   Rule(8),
   created(v0,v1).)_",
	R"_(created,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(9),
   created(v1,v0).)_",
	R"_(influences,v0,v1)_",
	R"_(inv_0(v0,v1) :- 
   Rule(10),
   influences(v0,v1).)_",
	R"_(influences,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(11),
   influences(v1,v0).)_",
	R"_(hasgeonamesid,v0,v1)_",
	R"_(inv_0(v0,v1) :- 
   Rule(12),
   hasgeonamesid(v0,v1).)_",
	R"_(hasgeonamesid,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(13),
   hasgeonamesid(v1,v0).)_",
	R"_(haswonprize,v0,v1)_",
	R"_(inv_0(v0,v1) :- 
   Rule(14),
   haswonprize(v0,v1).)_",
	R"_(haswonprize,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(15),
   haswonprize(v1,v0).)_",
	R"_(ismarriedto,v0,v1)_",
	R"_(inv_0(v0,v1) :- 
   Rule(16),
   ismarriedto(v0,v1).)_",
	R"_(ismarriedto,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(17),
   ismarriedto(v1,v0).)_",
	R"_(participatedin,v0,v1)_",
	R"_(inv_0(v0,v1) :- 
   Rule(18),
   participatedin(v0,v1).)_",
	R"_(participatedin,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(19),
   participatedin(v1,v0).)_",
	R"_(actedin,v0,v1)_",
	R"_(inv_0(v0,v1) :- 
   Rule(20),
   actedin(v0,v1).)_",
	R"_(actedin,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(21),
   actedin(v1,v0).)_",
	R"_(inv_0,v1,v0)_",
	R"_(inv_0(v0,v1) :- 
   Rule(25),
   inv_0(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(26),
   islocatedin(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(27),
   islocatedin(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(28),
   directed(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(29),
   directed(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(30),
   haschild(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(31),
   haschild(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(32),
   diedin(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(33),
   diedin(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(34),
   created(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(35),
   created(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(36),
   influences(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(37),
   influences(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(38),
   hasgeonamesid(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(39),
   hasgeonamesid(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(40),
   haswonprize(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(41),
   haswonprize(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(42),
   ismarriedto(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(43),
   ismarriedto(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(44),
   participatedin(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(45),
   participatedin(v1,v0).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(46),
   actedin(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(47),
   actedin(v1,v0).)_",
	R"_(inv_0,v0,v1)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(50),
   inv_0(v0,v1).)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(51),
   inv_0(v1,v0).)_",
	R"_(wasbornin,v1,v0)_",
	R"_(wasbornin(v0,v1) :- 
   Rule(53),
   wasbornin(v1,v0).)_",
};// -- Table: Rule
std::unique_ptr<t_btree_3__0_1_2__1__7> rel_1_Rule = std::make_unique<t_btree_3__0_1_2__1__7>();
souffle::RelationWrapper<0,t_btree_3__0_1_2__1__7,Tuple<RamDomain,3>,3> wrapper_rel_1_Rule;
// -- Table: actedin
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_2_actedin = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<1,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_2_actedin;
// -- Table: created
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_3_created = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<2,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_3_created;
// -- Table: diedin
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_4_diedin = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<3,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_4_diedin;
// -- Table: directed
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_5_directed = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<4,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_5_directed;
// -- Table: haschild
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_6_haschild = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<5,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_6_haschild;
// -- Table: hasgeonamesid
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_7_hasgeonamesid = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<6,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_7_hasgeonamesid;
// -- Table: haswonprize
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_8_haswonprize = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<7,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_8_haswonprize;
// -- Table: influences
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_9_influences = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<8,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_9_influences;
// -- Table: islocatedin
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_10_islocatedin = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<9,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_10_islocatedin;
// -- Table: ismarriedto
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_11_ismarriedto = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<10,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_11_ismarriedto;
// -- Table: participatedin
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_12_participatedin = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<11,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_12_participatedin;
// -- Table: inv_0
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_13_inv_0 = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<12,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_13_inv_0;
// -- Table: @delta_inv_0
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_14_delta_inv_0 = std::make_unique<t_btree_4__0_1_2_3__15>();
// -- Table: @new_inv_0
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_15_new_inv_0 = std::make_unique<t_btree_4__0_1_2_3__15>();
// -- Table: wasbornin
std::unique_ptr<t_btree_4__0_1_2_3__3__15> rel_16_wasbornin = std::make_unique<t_btree_4__0_1_2_3__3__15>();
souffle::RelationWrapper<13,t_btree_4__0_1_2_3__3__15,Tuple<RamDomain,4>,4> wrapper_rel_16_wasbornin;
// -- Table: @delta_wasbornin
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_17_delta_wasbornin = std::make_unique<t_btree_4__0_1_2_3__15>();
// -- Table: @new_wasbornin
std::unique_ptr<t_btree_4__0_1_2_3__15> rel_18_new_wasbornin = std::make_unique<t_btree_4__0_1_2_3__15>();
// -- Table: inv_0.@info.1
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_19_inv_0_info_1 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<14,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_19_inv_0_info_1;
// -- Table: inv_0.@info.10
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_20_inv_0_info_10 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<15,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_20_inv_0_info_10;
// -- Table: inv_0.@info.11
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_21_inv_0_info_11 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<16,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_21_inv_0_info_11;
// -- Table: inv_0.@info.12
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_22_inv_0_info_12 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<17,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_22_inv_0_info_12;
// -- Table: inv_0.@info.13
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_23_inv_0_info_13 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<18,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_23_inv_0_info_13;
// -- Table: inv_0.@info.14
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_24_inv_0_info_14 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<19,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_24_inv_0_info_14;
// -- Table: inv_0.@info.15
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_25_inv_0_info_15 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<20,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_25_inv_0_info_15;
// -- Table: inv_0.@info.16
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_26_inv_0_info_16 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<21,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_26_inv_0_info_16;
// -- Table: inv_0.@info.17
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_27_inv_0_info_17 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<22,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_27_inv_0_info_17;
// -- Table: inv_0.@info.18
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_28_inv_0_info_18 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<23,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_28_inv_0_info_18;
// -- Table: inv_0.@info.19
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_29_inv_0_info_19 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<24,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_29_inv_0_info_19;
// -- Table: inv_0.@info.2
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_30_inv_0_info_2 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<25,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_30_inv_0_info_2;
// -- Table: inv_0.@info.20
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_31_inv_0_info_20 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<26,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_31_inv_0_info_20;
// -- Table: inv_0.@info.21
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_32_inv_0_info_21 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<27,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_32_inv_0_info_21;
// -- Table: inv_0.@info.22
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_33_inv_0_info_22 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<28,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_33_inv_0_info_22;
// -- Table: inv_0.@info.23
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_34_inv_0_info_23 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<29,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_34_inv_0_info_23;
// -- Table: inv_0.@info.3
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_35_inv_0_info_3 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<30,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_35_inv_0_info_3;
// -- Table: inv_0.@info.4
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_36_inv_0_info_4 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<31,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_36_inv_0_info_4;
// -- Table: inv_0.@info.5
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_37_inv_0_info_5 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<32,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_37_inv_0_info_5;
// -- Table: inv_0.@info.6
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_38_inv_0_info_6 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<33,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_38_inv_0_info_6;
// -- Table: inv_0.@info.7
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_39_inv_0_info_7 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<34,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_39_inv_0_info_7;
// -- Table: inv_0.@info.8
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_40_inv_0_info_8 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<35,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_40_inv_0_info_8;
// -- Table: inv_0.@info.9
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_41_inv_0_info_9 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<36,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_41_inv_0_info_9;
// -- Table: wasbornin.@info.1
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_42_wasbornin_info_1 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<37,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_42_wasbornin_info_1;
// -- Table: wasbornin.@info.10
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_43_wasbornin_info_10 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<38,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_43_wasbornin_info_10;
// -- Table: wasbornin.@info.11
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_44_wasbornin_info_11 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<39,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_44_wasbornin_info_11;
// -- Table: wasbornin.@info.12
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_45_wasbornin_info_12 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<40,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_45_wasbornin_info_12;
// -- Table: wasbornin.@info.13
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_46_wasbornin_info_13 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<41,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_46_wasbornin_info_13;
// -- Table: wasbornin.@info.14
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_47_wasbornin_info_14 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<42,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_47_wasbornin_info_14;
// -- Table: wasbornin.@info.15
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_48_wasbornin_info_15 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<43,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_48_wasbornin_info_15;
// -- Table: wasbornin.@info.16
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_49_wasbornin_info_16 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<44,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_49_wasbornin_info_16;
// -- Table: wasbornin.@info.17
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_50_wasbornin_info_17 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<45,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_50_wasbornin_info_17;
// -- Table: wasbornin.@info.18
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_51_wasbornin_info_18 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<46,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_51_wasbornin_info_18;
// -- Table: wasbornin.@info.19
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_52_wasbornin_info_19 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<47,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_52_wasbornin_info_19;
// -- Table: wasbornin.@info.2
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_53_wasbornin_info_2 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<48,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_53_wasbornin_info_2;
// -- Table: wasbornin.@info.20
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_54_wasbornin_info_20 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<49,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_54_wasbornin_info_20;
// -- Table: wasbornin.@info.21
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_55_wasbornin_info_21 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<50,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_55_wasbornin_info_21;
// -- Table: wasbornin.@info.22
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_56_wasbornin_info_22 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<51,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_56_wasbornin_info_22;
// -- Table: wasbornin.@info.23
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_57_wasbornin_info_23 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<52,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_57_wasbornin_info_23;
// -- Table: wasbornin.@info.24
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_58_wasbornin_info_24 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<53,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_58_wasbornin_info_24;
// -- Table: wasbornin.@info.25
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_59_wasbornin_info_25 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<54,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_59_wasbornin_info_25;
// -- Table: wasbornin.@info.3
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_60_wasbornin_info_3 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<55,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_60_wasbornin_info_3;
// -- Table: wasbornin.@info.4
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_61_wasbornin_info_4 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<56,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_61_wasbornin_info_4;
// -- Table: wasbornin.@info.5
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_62_wasbornin_info_5 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<57,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_62_wasbornin_info_5;
// -- Table: wasbornin.@info.6
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_63_wasbornin_info_6 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<58,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_63_wasbornin_info_6;
// -- Table: wasbornin.@info.7
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_64_wasbornin_info_7 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<59,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_64_wasbornin_info_7;
// -- Table: wasbornin.@info.8
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_65_wasbornin_info_8 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<60,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_65_wasbornin_info_8;
// -- Table: wasbornin.@info.9
std::unique_ptr<t_btree_5__0_1_2_3_4__31> rel_66_wasbornin_info_9 = std::make_unique<t_btree_5__0_1_2_3_4__31>();
souffle::RelationWrapper<61,t_btree_5__0_1_2_3_4__31,Tuple<RamDomain,5>,5> wrapper_rel_66_wasbornin_info_9;
public:
Sf_souffle_small() : 
wrapper_rel_1_Rule(*rel_1_Rule,symTable,"Rule",std::array<const char *,3>{{"i:number","i:number","i:number"}},std::array<const char *,3>{{"n","@rule_number","@level_number"}}),

wrapper_rel_2_actedin(*rel_2_actedin,symTable,"actedin",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_3_created(*rel_3_created,symTable,"created",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_4_diedin(*rel_4_diedin,symTable,"diedin",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_5_directed(*rel_5_directed,symTable,"directed",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_6_haschild(*rel_6_haschild,symTable,"haschild",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_7_hasgeonamesid(*rel_7_hasgeonamesid,symTable,"hasgeonamesid",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_8_haswonprize(*rel_8_haswonprize,symTable,"haswonprize",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_9_influences(*rel_9_influences,symTable,"influences",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_10_islocatedin(*rel_10_islocatedin,symTable,"islocatedin",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_11_ismarriedto(*rel_11_ismarriedto,symTable,"ismarriedto",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_12_participatedin(*rel_12_participatedin,symTable,"participatedin",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_13_inv_0(*rel_13_inv_0,symTable,"inv_0",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_16_wasbornin(*rel_16_wasbornin,symTable,"wasbornin",std::array<const char *,4>{{"s:V","s:V","i:number","i:number"}},std::array<const char *,4>{{"v0","v1","@rule_number","@level_number"}}),

wrapper_rel_19_inv_0_info_1(*rel_19_inv_0_info_1,symTable,"inv_0.@info.1",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_20_inv_0_info_10(*rel_20_inv_0_info_10,symTable,"inv_0.@info.10",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_21_inv_0_info_11(*rel_21_inv_0_info_11,symTable,"inv_0.@info.11",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_22_inv_0_info_12(*rel_22_inv_0_info_12,symTable,"inv_0.@info.12",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_23_inv_0_info_13(*rel_23_inv_0_info_13,symTable,"inv_0.@info.13",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_24_inv_0_info_14(*rel_24_inv_0_info_14,symTable,"inv_0.@info.14",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_25_inv_0_info_15(*rel_25_inv_0_info_15,symTable,"inv_0.@info.15",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_26_inv_0_info_16(*rel_26_inv_0_info_16,symTable,"inv_0.@info.16",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_27_inv_0_info_17(*rel_27_inv_0_info_17,symTable,"inv_0.@info.17",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_28_inv_0_info_18(*rel_28_inv_0_info_18,symTable,"inv_0.@info.18",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_29_inv_0_info_19(*rel_29_inv_0_info_19,symTable,"inv_0.@info.19",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_30_inv_0_info_2(*rel_30_inv_0_info_2,symTable,"inv_0.@info.2",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_31_inv_0_info_20(*rel_31_inv_0_info_20,symTable,"inv_0.@info.20",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_32_inv_0_info_21(*rel_32_inv_0_info_21,symTable,"inv_0.@info.21",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_33_inv_0_info_22(*rel_33_inv_0_info_22,symTable,"inv_0.@info.22",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_34_inv_0_info_23(*rel_34_inv_0_info_23,symTable,"inv_0.@info.23",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_35_inv_0_info_3(*rel_35_inv_0_info_3,symTable,"inv_0.@info.3",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_36_inv_0_info_4(*rel_36_inv_0_info_4,symTable,"inv_0.@info.4",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_37_inv_0_info_5(*rel_37_inv_0_info_5,symTable,"inv_0.@info.5",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_38_inv_0_info_6(*rel_38_inv_0_info_6,symTable,"inv_0.@info.6",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_39_inv_0_info_7(*rel_39_inv_0_info_7,symTable,"inv_0.@info.7",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_40_inv_0_info_8(*rel_40_inv_0_info_8,symTable,"inv_0.@info.8",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_41_inv_0_info_9(*rel_41_inv_0_info_9,symTable,"inv_0.@info.9",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_42_wasbornin_info_1(*rel_42_wasbornin_info_1,symTable,"wasbornin.@info.1",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_43_wasbornin_info_10(*rel_43_wasbornin_info_10,symTable,"wasbornin.@info.10",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_44_wasbornin_info_11(*rel_44_wasbornin_info_11,symTable,"wasbornin.@info.11",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_45_wasbornin_info_12(*rel_45_wasbornin_info_12,symTable,"wasbornin.@info.12",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_46_wasbornin_info_13(*rel_46_wasbornin_info_13,symTable,"wasbornin.@info.13",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_47_wasbornin_info_14(*rel_47_wasbornin_info_14,symTable,"wasbornin.@info.14",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_48_wasbornin_info_15(*rel_48_wasbornin_info_15,symTable,"wasbornin.@info.15",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_49_wasbornin_info_16(*rel_49_wasbornin_info_16,symTable,"wasbornin.@info.16",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_50_wasbornin_info_17(*rel_50_wasbornin_info_17,symTable,"wasbornin.@info.17",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_51_wasbornin_info_18(*rel_51_wasbornin_info_18,symTable,"wasbornin.@info.18",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_52_wasbornin_info_19(*rel_52_wasbornin_info_19,symTable,"wasbornin.@info.19",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_53_wasbornin_info_2(*rel_53_wasbornin_info_2,symTable,"wasbornin.@info.2",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_54_wasbornin_info_20(*rel_54_wasbornin_info_20,symTable,"wasbornin.@info.20",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_55_wasbornin_info_21(*rel_55_wasbornin_info_21,symTable,"wasbornin.@info.21",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_56_wasbornin_info_22(*rel_56_wasbornin_info_22,symTable,"wasbornin.@info.22",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_57_wasbornin_info_23(*rel_57_wasbornin_info_23,symTable,"wasbornin.@info.23",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_58_wasbornin_info_24(*rel_58_wasbornin_info_24,symTable,"wasbornin.@info.24",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_59_wasbornin_info_25(*rel_59_wasbornin_info_25,symTable,"wasbornin.@info.25",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_60_wasbornin_info_3(*rel_60_wasbornin_info_3,symTable,"wasbornin.@info.3",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_61_wasbornin_info_4(*rel_61_wasbornin_info_4,symTable,"wasbornin.@info.4",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_62_wasbornin_info_5(*rel_62_wasbornin_info_5,symTable,"wasbornin.@info.5",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_63_wasbornin_info_6(*rel_63_wasbornin_info_6,symTable,"wasbornin.@info.6",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_64_wasbornin_info_7(*rel_64_wasbornin_info_7,symTable,"wasbornin.@info.7",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_65_wasbornin_info_8(*rel_65_wasbornin_info_8,symTable,"wasbornin.@info.8",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}),

wrapper_rel_66_wasbornin_info_9(*rel_66_wasbornin_info_9,symTable,"wasbornin.@info.9",std::array<const char *,5>{{"i:number","s:symbol","s:symbol","s:symbol","s:symbol"}},std::array<const char *,5>{{"clause_num","head_vars","rel_0","rel_1","clause_repr"}}){
addRelation("Rule",&wrapper_rel_1_Rule,true,false);
addRelation("actedin",&wrapper_rel_2_actedin,true,false);
addRelation("created",&wrapper_rel_3_created,true,false);
addRelation("diedin",&wrapper_rel_4_diedin,true,false);
addRelation("directed",&wrapper_rel_5_directed,true,false);
addRelation("haschild",&wrapper_rel_6_haschild,true,false);
addRelation("hasgeonamesid",&wrapper_rel_7_hasgeonamesid,true,false);
addRelation("haswonprize",&wrapper_rel_8_haswonprize,true,false);
addRelation("influences",&wrapper_rel_9_influences,true,false);
addRelation("islocatedin",&wrapper_rel_10_islocatedin,true,false);
addRelation("ismarriedto",&wrapper_rel_11_ismarriedto,true,false);
addRelation("participatedin",&wrapper_rel_12_participatedin,true,false);
addRelation("inv_0",&wrapper_rel_13_inv_0,false,true);
addRelation("wasbornin",&wrapper_rel_16_wasbornin,false,true);
addRelation("inv_0.@info.1",&wrapper_rel_19_inv_0_info_1,false,false);
addRelation("inv_0.@info.10",&wrapper_rel_20_inv_0_info_10,false,false);
addRelation("inv_0.@info.11",&wrapper_rel_21_inv_0_info_11,false,false);
addRelation("inv_0.@info.12",&wrapper_rel_22_inv_0_info_12,false,false);
addRelation("inv_0.@info.13",&wrapper_rel_23_inv_0_info_13,false,false);
addRelation("inv_0.@info.14",&wrapper_rel_24_inv_0_info_14,false,false);
addRelation("inv_0.@info.15",&wrapper_rel_25_inv_0_info_15,false,false);
addRelation("inv_0.@info.16",&wrapper_rel_26_inv_0_info_16,false,false);
addRelation("inv_0.@info.17",&wrapper_rel_27_inv_0_info_17,false,false);
addRelation("inv_0.@info.18",&wrapper_rel_28_inv_0_info_18,false,false);
addRelation("inv_0.@info.19",&wrapper_rel_29_inv_0_info_19,false,false);
addRelation("inv_0.@info.2",&wrapper_rel_30_inv_0_info_2,false,false);
addRelation("inv_0.@info.20",&wrapper_rel_31_inv_0_info_20,false,false);
addRelation("inv_0.@info.21",&wrapper_rel_32_inv_0_info_21,false,false);
addRelation("inv_0.@info.22",&wrapper_rel_33_inv_0_info_22,false,false);
addRelation("inv_0.@info.23",&wrapper_rel_34_inv_0_info_23,false,false);
addRelation("inv_0.@info.3",&wrapper_rel_35_inv_0_info_3,false,false);
addRelation("inv_0.@info.4",&wrapper_rel_36_inv_0_info_4,false,false);
addRelation("inv_0.@info.5",&wrapper_rel_37_inv_0_info_5,false,false);
addRelation("inv_0.@info.6",&wrapper_rel_38_inv_0_info_6,false,false);
addRelation("inv_0.@info.7",&wrapper_rel_39_inv_0_info_7,false,false);
addRelation("inv_0.@info.8",&wrapper_rel_40_inv_0_info_8,false,false);
addRelation("inv_0.@info.9",&wrapper_rel_41_inv_0_info_9,false,false);
addRelation("wasbornin.@info.1",&wrapper_rel_42_wasbornin_info_1,false,false);
addRelation("wasbornin.@info.10",&wrapper_rel_43_wasbornin_info_10,false,false);
addRelation("wasbornin.@info.11",&wrapper_rel_44_wasbornin_info_11,false,false);
addRelation("wasbornin.@info.12",&wrapper_rel_45_wasbornin_info_12,false,false);
addRelation("wasbornin.@info.13",&wrapper_rel_46_wasbornin_info_13,false,false);
addRelation("wasbornin.@info.14",&wrapper_rel_47_wasbornin_info_14,false,false);
addRelation("wasbornin.@info.15",&wrapper_rel_48_wasbornin_info_15,false,false);
addRelation("wasbornin.@info.16",&wrapper_rel_49_wasbornin_info_16,false,false);
addRelation("wasbornin.@info.17",&wrapper_rel_50_wasbornin_info_17,false,false);
addRelation("wasbornin.@info.18",&wrapper_rel_51_wasbornin_info_18,false,false);
addRelation("wasbornin.@info.19",&wrapper_rel_52_wasbornin_info_19,false,false);
addRelation("wasbornin.@info.2",&wrapper_rel_53_wasbornin_info_2,false,false);
addRelation("wasbornin.@info.20",&wrapper_rel_54_wasbornin_info_20,false,false);
addRelation("wasbornin.@info.21",&wrapper_rel_55_wasbornin_info_21,false,false);
addRelation("wasbornin.@info.22",&wrapper_rel_56_wasbornin_info_22,false,false);
addRelation("wasbornin.@info.23",&wrapper_rel_57_wasbornin_info_23,false,false);
addRelation("wasbornin.@info.24",&wrapper_rel_58_wasbornin_info_24,false,false);
addRelation("wasbornin.@info.25",&wrapper_rel_59_wasbornin_info_25,false,false);
addRelation("wasbornin.@info.3",&wrapper_rel_60_wasbornin_info_3,false,false);
addRelation("wasbornin.@info.4",&wrapper_rel_61_wasbornin_info_4,false,false);
addRelation("wasbornin.@info.5",&wrapper_rel_62_wasbornin_info_5,false,false);
addRelation("wasbornin.@info.6",&wrapper_rel_63_wasbornin_info_6,false,false);
addRelation("wasbornin.@info.7",&wrapper_rel_64_wasbornin_info_7,false,false);
addRelation("wasbornin.@info.8",&wrapper_rel_65_wasbornin_info_8,false,false);
addRelation("wasbornin.@info.9",&wrapper_rel_66_wasbornin_info_9,false,false);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./actedin.facts"},{"name","actedin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_2_actedin);
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
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./diedin.facts"},{"name","diedin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_4_diedin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 3 */
/* BEGIN STRATUM 4 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./directed.facts"},{"name","directed"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_5_directed);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 4 */
/* BEGIN STRATUM 5 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./haschild.facts"},{"name","haschild"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_6_haschild);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 5 */
/* BEGIN STRATUM 6 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./hasgeonamesid.facts"},{"name","hasgeonamesid"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_7_hasgeonamesid);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 6 */
/* BEGIN STRATUM 7 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./haswonprize.facts"},{"name","haswonprize"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_8_haswonprize);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 7 */
/* BEGIN STRATUM 8 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./influences.facts"},{"name","influences"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_9_influences);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 8 */
/* BEGIN STRATUM 9 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./islocatedin.facts"},{"name","islocatedin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_10_islocatedin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 9 */
/* BEGIN STRATUM 10 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./ismarriedto.facts"},{"name","ismarriedto"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_11_ismarriedto);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 10 */
/* BEGIN STRATUM 11 */
[&]() {
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./participatedin.facts"},{"name","participatedin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_12_participatedin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
}
}();
/* END STRATUM 11 */
/* BEGIN STRATUM 12 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,1,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(0,_,@level_num_0),
   islocatedin(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [50:1-50:47])_");
if(!(rel_10_islocatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(0),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_10_islocatedin_op_ctxt,rel_10_islocatedin->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_10_islocatedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(1)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,2,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(1,_,@level_num_0),
   islocatedin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [51:1-51:47])_");
if(!(rel_10_islocatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(1),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_10_islocatedin_op_ctxt,rel_10_islocatedin->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_10_islocatedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(2)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,3,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(2,_,@level_num_0),
   directed(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [52:1-52:44])_");
if(!(rel_5_directed->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(2),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_directed_op_ctxt,rel_5_directed->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_directed) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(3)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,4,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(3,_,@level_num_0),
   directed(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [53:1-53:44])_");
if(!(rel_5_directed->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(3),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_directed_op_ctxt,rel_5_directed->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_directed) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(4)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,5,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(4,_,@level_num_0),
   haschild(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [54:1-54:44])_");
if(!(rel_6_haschild->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(4),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_6_haschild_op_ctxt,rel_6_haschild->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_6_haschild) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(5)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,6,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(5,_,@level_num_0),
   haschild(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [55:1-55:44])_");
if(!(rel_6_haschild->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(5),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_6_haschild_op_ctxt,rel_6_haschild->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_6_haschild) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(6)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,7,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(6,_,@level_num_0),
   diedin(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [56:1-56:42])_");
if(!(rel_4_diedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(6),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_diedin_op_ctxt,rel_4_diedin->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_diedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(7)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,8,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(7,_,@level_num_0),
   diedin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [57:1-57:42])_");
if(!(rel_4_diedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(7),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_diedin_op_ctxt,rel_4_diedin->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_diedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(8)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,9,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(8,_,@level_num_0),
   created(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [58:1-58:43])_");
if(!(rel_3_created->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(8),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_created) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(9)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,10,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(9,_,@level_num_0),
   created(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [59:1-59:43])_");
if(!(rel_3_created->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(9),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_created) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(10)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,11,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(10,_,@level_num_0),
   influences(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [60:1-60:47])_");
if(!(rel_9_influences->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(10),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_9_influences_op_ctxt,rel_9_influences->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_9_influences) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(11)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,12,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(11,_,@level_num_0),
   influences(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [61:1-61:47])_");
if(!(rel_9_influences->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(11),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_9_influences_op_ctxt,rel_9_influences->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_9_influences) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(12)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,13,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(12,_,@level_num_0),
   hasgeonamesid(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [62:1-62:50])_");
if(!(rel_7_hasgeonamesid->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(12),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt,rel_7_hasgeonamesid->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_7_hasgeonamesid) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(13)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,14,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(13,_,@level_num_0),
   hasgeonamesid(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [63:1-63:50])_");
if(!(rel_7_hasgeonamesid->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(13),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt,rel_7_hasgeonamesid->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_7_hasgeonamesid) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(14)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,15,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(14,_,@level_num_0),
   haswonprize(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [64:1-64:48])_");
if(!(rel_8_haswonprize->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(14),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_haswonprize_op_ctxt,rel_8_haswonprize->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_haswonprize) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(15)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,16,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(15,_,@level_num_0),
   haswonprize(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [65:1-65:48])_");
if(!(rel_8_haswonprize->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(15),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_haswonprize_op_ctxt,rel_8_haswonprize->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_haswonprize) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(16)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,17,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(16,_,@level_num_0),
   ismarriedto(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [66:1-66:48])_");
if(!(rel_11_ismarriedto->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(16),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_11_ismarriedto_op_ctxt,rel_11_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_11_ismarriedto) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(17)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,18,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(17,_,@level_num_0),
   ismarriedto(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [67:1-67:48])_");
if(!(rel_11_ismarriedto->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(17),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_11_ismarriedto_op_ctxt,rel_11_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_11_ismarriedto) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(18)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,19,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(18,_,@level_num_0),
   participatedin(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [68:1-68:51])_");
if(!(rel_12_participatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(18),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_12_participatedin_op_ctxt,rel_12_participatedin->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_12_participatedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(19)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,20,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(19,_,@level_num_0),
   participatedin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [69:1-69:51])_");
if(!(rel_12_participatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(19),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_12_participatedin_op_ctxt,rel_12_participatedin->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_12_participatedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(20)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,21,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(20,_,@level_num_0),
   actedin(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [70:1-70:44])_");
if(!(rel_2_actedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(20),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_2_actedin_op_ctxt,rel_2_actedin->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_2_actedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(21)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,22,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(21,_,@level_num_0),
   actedin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [71:1-71:44])_");
if(!(rel_2_actedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(21),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_2_actedin_op_ctxt,rel_2_actedin->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_2_actedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(22)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_13_inv_0->insert(tuple,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
rel_14_delta_inv_0->insertAll(*rel_13_inv_0);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(inv_0(v0,v1,23,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(25,_,@level_num_0),
   inv_0(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [72:1-72:42])_");
if(!(rel_14_delta_inv_0->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(25),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
CREATE_OP_CONTEXT(rel_14_delta_inv_0_op_ctxt,rel_14_delta_inv_0->createContext());
CREATE_OP_CONTEXT(rel_15_new_inv_0_op_ctxt,rel_15_new_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_14_delta_inv_0) {
if( !([&]() -> bool {
auto existenceCheck = rel_13_inv_0->equalRange_3(Tuple<RamDomain,4>({{env1[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({env0[2], env1[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(23)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_15_new_inv_0->insert(tuple,READ_OP_CONTEXT(rel_15_new_inv_0_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
if(rel_15_new_inv_0->empty()) break;
rel_13_inv_0->insertAll(*rel_15_new_inv_0);
std::swap(rel_14_delta_inv_0, rel_15_new_inv_0);
rel_15_new_inv_0->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_14_delta_inv_0->purge();
if (!isHintsProfilingEnabled()) rel_15_new_inv_0->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./inv_0.csv"},{"name","inv_0"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_13_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 12 */
/* BEGIN STRATUM 13 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,1,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(26,_,@level_num_0),
   islocatedin(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [73:1-73:52])_");
if(!(rel_10_islocatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(26),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_10_islocatedin_op_ctxt,rel_10_islocatedin->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_10_islocatedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(1)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,2,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(27,_,@level_num_0),
   islocatedin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [74:1-74:52])_");
if(!(rel_10_islocatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(27),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_10_islocatedin_op_ctxt,rel_10_islocatedin->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_10_islocatedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(2)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,3,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(28,_,@level_num_0),
   directed(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [75:1-75:49])_");
if(!(rel_5_directed->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(28),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_directed_op_ctxt,rel_5_directed->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_directed) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(3)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,4,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(29,_,@level_num_0),
   directed(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [76:1-76:49])_");
if(!(rel_5_directed->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(29),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_directed_op_ctxt,rel_5_directed->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_5_directed) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(4)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,5,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(30,_,@level_num_0),
   haschild(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [77:1-77:49])_");
if(!(rel_6_haschild->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(30),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_6_haschild_op_ctxt,rel_6_haschild->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_6_haschild) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(5)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,6,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(31,_,@level_num_0),
   haschild(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [78:1-78:49])_");
if(!(rel_6_haschild->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(31),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_6_haschild_op_ctxt,rel_6_haschild->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_6_haschild) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(6)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,7,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(32,_,@level_num_0),
   diedin(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [79:1-79:47])_");
if(!(rel_4_diedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(32),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_diedin_op_ctxt,rel_4_diedin->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_diedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(7)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,8,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(33,_,@level_num_0),
   diedin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [80:1-80:47])_");
if(!(rel_4_diedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(33),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_diedin_op_ctxt,rel_4_diedin->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_4_diedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(8)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,9,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(34,_,@level_num_0),
   created(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [81:1-81:48])_");
if(!(rel_3_created->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(34),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_created) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(9)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,10,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(35,_,@level_num_0),
   created(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [82:1-82:48])_");
if(!(rel_3_created->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(35),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_3_created) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(10)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,11,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(36,_,@level_num_0),
   influences(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [83:1-83:51])_");
if(!(rel_9_influences->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(36),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_9_influences_op_ctxt,rel_9_influences->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_9_influences) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(11)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,12,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(37,_,@level_num_0),
   influences(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [84:1-84:51])_");
if(!(rel_9_influences->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(37),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_9_influences_op_ctxt,rel_9_influences->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_9_influences) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(12)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,13,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(38,_,@level_num_0),
   hasgeonamesid(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [85:1-85:54])_");
if(!(rel_7_hasgeonamesid->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(38),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt,rel_7_hasgeonamesid->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_7_hasgeonamesid) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(13)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,14,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(39,_,@level_num_0),
   hasgeonamesid(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [86:1-86:54])_");
if(!(rel_7_hasgeonamesid->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(39),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt,rel_7_hasgeonamesid->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_7_hasgeonamesid) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(14)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,15,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(40,_,@level_num_0),
   haswonprize(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [87:1-87:52])_");
if(!(rel_8_haswonprize->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(40),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_haswonprize_op_ctxt,rel_8_haswonprize->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_haswonprize) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(15)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,16,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(41,_,@level_num_0),
   haswonprize(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [88:1-88:52])_");
if(!(rel_8_haswonprize->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(41),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_haswonprize_op_ctxt,rel_8_haswonprize->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_8_haswonprize) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(16)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,17,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(42,_,@level_num_0),
   ismarriedto(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [89:1-89:52])_");
if(!(rel_11_ismarriedto->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(42),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_11_ismarriedto_op_ctxt,rel_11_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_11_ismarriedto) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(17)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,18,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(43,_,@level_num_0),
   ismarriedto(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [90:1-90:52])_");
if(!(rel_11_ismarriedto->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(43),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_11_ismarriedto_op_ctxt,rel_11_ismarriedto->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_11_ismarriedto) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(18)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,19,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(44,_,@level_num_0),
   participatedin(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [91:1-91:55])_");
if(!(rel_12_participatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(44),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_12_participatedin_op_ctxt,rel_12_participatedin->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_12_participatedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(19)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,20,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(45,_,@level_num_0),
   participatedin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [92:1-92:55])_");
if(!(rel_12_participatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(45),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_12_participatedin_op_ctxt,rel_12_participatedin->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_12_participatedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(20)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,21,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(46,_,@level_num_0),
   actedin(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [93:1-93:48])_");
if(!(rel_2_actedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(46),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_2_actedin_op_ctxt,rel_2_actedin->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_2_actedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(21)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,22,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(47,_,@level_num_0),
   actedin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [94:1-94:48])_");
if(!(rel_2_actedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(47),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_2_actedin_op_ctxt,rel_2_actedin->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_2_actedin) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(22)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,23,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(50,_,@level_num_0),
   inv_0(v0,v1,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [95:1-95:46])_");
if(!(rel_13_inv_0->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(50),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_13_inv_0) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(RamDomain(23)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,24,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(51,_,@level_num_0),
   inv_0(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [96:1-96:46])_");
if(!(rel_13_inv_0->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(51),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_13_inv_0) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(24)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_16_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
rel_17_delta_wasbornin->insertAll(*rel_16_wasbornin);
iter = 0;
for(;;) {
SignalHandler::instance()->setMsg(R"_(wasbornin(v0,v1,25,(max(@level_num_0,@level_num_1)+1)) :- 
   Rule(53,_,@level_num_0),
   wasbornin(v1,v0,_,@level_num_1).
in file /home/johannes_tantow/DatalogLearning/prosynth/yago/rules.dl [97:1-97:50])_");
if(!(rel_17_delta_wasbornin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(53),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_18_new_wasbornin_op_ctxt,rel_18_new_wasbornin->createContext());
CREATE_OP_CONTEXT(rel_17_delta_wasbornin_op_ctxt,rel_17_delta_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
for(const auto& env1 : *rel_17_delta_wasbornin) {
if( !([&]() -> bool {
auto existenceCheck = rel_16_wasbornin->equalRange_3(Tuple<RamDomain,4>({{env1[1],env1[0],0,0}}),READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
if (existenceCheck.empty()) return false; else return (*existenceCheck.begin())[3] <= (std::max({env0[2], env1[3], })) + (RamDomain(1));}()
)) {
Tuple<RamDomain,4> tuple({{static_cast<RamDomain>(env1[1]),static_cast<RamDomain>(env1[0]),static_cast<RamDomain>(RamDomain(25)),static_cast<RamDomain>((std::max({env0[2], env1[3], })) + (RamDomain(1)))}});
rel_18_new_wasbornin->insert(tuple,READ_OP_CONTEXT(rel_18_new_wasbornin_op_ctxt));
}
}
}
} catch(std::exception &e) { SignalHandler::instance()->error(e.what());}
}
PARALLEL_END;
}
();}
if(rel_18_new_wasbornin->empty()) break;
rel_16_wasbornin->insertAll(*rel_18_new_wasbornin);
std::swap(rel_17_delta_wasbornin, rel_18_new_wasbornin);
rel_18_new_wasbornin->purge();
iter++;
}
iter = 0;
if (!isHintsProfilingEnabled()) rel_17_delta_wasbornin->purge();
if (!isHintsProfilingEnabled()) rel_18_new_wasbornin->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./wasbornin.csv"},{"name","wasbornin"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_16_wasbornin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}();
/* END STRATUM 13 */
/* BEGIN STRATUM 14 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.1(1,"v0,v1","Rule","islocatedin,v0,v1","inv_0(v0,v1) :- 
   Rule(0),
   islocatedin(v0,v1).").
in file  [0:0-0:0])_");
rel_19_inv_0_info_1->insert(RamDomain(1),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(3));
}();
/* END STRATUM 14 */
/* BEGIN STRATUM 15 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.10(10,"v0,v1","Rule","created,v1,v0","inv_0(v0,v1) :- 
   Rule(9),
   created(v1,v0).").
in file  [0:0-0:0])_");
rel_20_inv_0_info_10->insert(RamDomain(10),RamDomain(0),RamDomain(1),RamDomain(20),RamDomain(21));
}();
/* END STRATUM 15 */
/* BEGIN STRATUM 16 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.11(11,"v0,v1","Rule","influences,v0,v1","inv_0(v0,v1) :- 
   Rule(10),
   influences(v0,v1).").
in file  [0:0-0:0])_");
rel_21_inv_0_info_11->insert(RamDomain(11),RamDomain(0),RamDomain(1),RamDomain(22),RamDomain(23));
}();
/* END STRATUM 16 */
/* BEGIN STRATUM 17 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.12(12,"v0,v1","Rule","influences,v1,v0","inv_0(v0,v1) :- 
   Rule(11),
   influences(v1,v0).").
in file  [0:0-0:0])_");
rel_22_inv_0_info_12->insert(RamDomain(12),RamDomain(0),RamDomain(1),RamDomain(24),RamDomain(25));
}();
/* END STRATUM 17 */
/* BEGIN STRATUM 18 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.13(13,"v0,v1","Rule","hasgeonamesid,v0,v1","inv_0(v0,v1) :- 
   Rule(12),
   hasgeonamesid(v0,v1).").
in file  [0:0-0:0])_");
rel_23_inv_0_info_13->insert(RamDomain(13),RamDomain(0),RamDomain(1),RamDomain(26),RamDomain(27));
}();
/* END STRATUM 18 */
/* BEGIN STRATUM 19 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.14(14,"v0,v1","Rule","hasgeonamesid,v1,v0","inv_0(v0,v1) :- 
   Rule(13),
   hasgeonamesid(v1,v0).").
in file  [0:0-0:0])_");
rel_24_inv_0_info_14->insert(RamDomain(14),RamDomain(0),RamDomain(1),RamDomain(28),RamDomain(29));
}();
/* END STRATUM 19 */
/* BEGIN STRATUM 20 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.15(15,"v0,v1","Rule","haswonprize,v0,v1","inv_0(v0,v1) :- 
   Rule(14),
   haswonprize(v0,v1).").
in file  [0:0-0:0])_");
rel_25_inv_0_info_15->insert(RamDomain(15),RamDomain(0),RamDomain(1),RamDomain(30),RamDomain(31));
}();
/* END STRATUM 20 */
/* BEGIN STRATUM 21 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.16(16,"v0,v1","Rule","haswonprize,v1,v0","inv_0(v0,v1) :- 
   Rule(15),
   haswonprize(v1,v0).").
in file  [0:0-0:0])_");
rel_26_inv_0_info_16->insert(RamDomain(16),RamDomain(0),RamDomain(1),RamDomain(32),RamDomain(33));
}();
/* END STRATUM 21 */
/* BEGIN STRATUM 22 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.17(17,"v0,v1","Rule","ismarriedto,v0,v1","inv_0(v0,v1) :- 
   Rule(16),
   ismarriedto(v0,v1).").
in file  [0:0-0:0])_");
rel_27_inv_0_info_17->insert(RamDomain(17),RamDomain(0),RamDomain(1),RamDomain(34),RamDomain(35));
}();
/* END STRATUM 22 */
/* BEGIN STRATUM 23 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.18(18,"v0,v1","Rule","ismarriedto,v1,v0","inv_0(v0,v1) :- 
   Rule(17),
   ismarriedto(v1,v0).").
in file  [0:0-0:0])_");
rel_28_inv_0_info_18->insert(RamDomain(18),RamDomain(0),RamDomain(1),RamDomain(36),RamDomain(37));
}();
/* END STRATUM 23 */
/* BEGIN STRATUM 24 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.19(19,"v0,v1","Rule","participatedin,v0,v1","inv_0(v0,v1) :- 
   Rule(18),
   participatedin(v0,v1).").
in file  [0:0-0:0])_");
rel_29_inv_0_info_19->insert(RamDomain(19),RamDomain(0),RamDomain(1),RamDomain(38),RamDomain(39));
}();
/* END STRATUM 24 */
/* BEGIN STRATUM 25 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.2(2,"v0,v1","Rule","islocatedin,v1,v0","inv_0(v0,v1) :- 
   Rule(1),
   islocatedin(v1,v0).").
in file  [0:0-0:0])_");
rel_30_inv_0_info_2->insert(RamDomain(2),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(5));
}();
/* END STRATUM 25 */
/* BEGIN STRATUM 26 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.20(20,"v0,v1","Rule","participatedin,v1,v0","inv_0(v0,v1) :- 
   Rule(19),
   participatedin(v1,v0).").
in file  [0:0-0:0])_");
rel_31_inv_0_info_20->insert(RamDomain(20),RamDomain(0),RamDomain(1),RamDomain(40),RamDomain(41));
}();
/* END STRATUM 26 */
/* BEGIN STRATUM 27 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.21(21,"v0,v1","Rule","actedin,v0,v1","inv_0(v0,v1) :- 
   Rule(20),
   actedin(v0,v1).").
in file  [0:0-0:0])_");
rel_32_inv_0_info_21->insert(RamDomain(21),RamDomain(0),RamDomain(1),RamDomain(42),RamDomain(43));
}();
/* END STRATUM 27 */
/* BEGIN STRATUM 28 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.22(22,"v0,v1","Rule","actedin,v1,v0","inv_0(v0,v1) :- 
   Rule(21),
   actedin(v1,v0).").
in file  [0:0-0:0])_");
rel_33_inv_0_info_22->insert(RamDomain(22),RamDomain(0),RamDomain(1),RamDomain(44),RamDomain(45));
}();
/* END STRATUM 28 */
/* BEGIN STRATUM 29 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.23(23,"v0,v1","Rule","inv_0,v1,v0","inv_0(v0,v1) :- 
   Rule(25),
   inv_0(v1,v0).").
in file  [0:0-0:0])_");
rel_34_inv_0_info_23->insert(RamDomain(23),RamDomain(0),RamDomain(1),RamDomain(46),RamDomain(47));
}();
/* END STRATUM 29 */
/* BEGIN STRATUM 30 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.3(3,"v0,v1","Rule","directed,v0,v1","inv_0(v0,v1) :- 
   Rule(2),
   directed(v0,v1).").
in file  [0:0-0:0])_");
rel_35_inv_0_info_3->insert(RamDomain(3),RamDomain(0),RamDomain(1),RamDomain(6),RamDomain(7));
}();
/* END STRATUM 30 */
/* BEGIN STRATUM 31 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.4(4,"v0,v1","Rule","directed,v1,v0","inv_0(v0,v1) :- 
   Rule(3),
   directed(v1,v0).").
in file  [0:0-0:0])_");
rel_36_inv_0_info_4->insert(RamDomain(4),RamDomain(0),RamDomain(1),RamDomain(8),RamDomain(9));
}();
/* END STRATUM 31 */
/* BEGIN STRATUM 32 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.5(5,"v0,v1","Rule","haschild,v0,v1","inv_0(v0,v1) :- 
   Rule(4),
   haschild(v0,v1).").
in file  [0:0-0:0])_");
rel_37_inv_0_info_5->insert(RamDomain(5),RamDomain(0),RamDomain(1),RamDomain(10),RamDomain(11));
}();
/* END STRATUM 32 */
/* BEGIN STRATUM 33 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.6(6,"v0,v1","Rule","haschild,v1,v0","inv_0(v0,v1) :- 
   Rule(5),
   haschild(v1,v0).").
in file  [0:0-0:0])_");
rel_38_inv_0_info_6->insert(RamDomain(6),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(13));
}();
/* END STRATUM 33 */
/* BEGIN STRATUM 34 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.7(7,"v0,v1","Rule","diedin,v0,v1","inv_0(v0,v1) :- 
   Rule(6),
   diedin(v0,v1).").
in file  [0:0-0:0])_");
rel_39_inv_0_info_7->insert(RamDomain(7),RamDomain(0),RamDomain(1),RamDomain(14),RamDomain(15));
}();
/* END STRATUM 34 */
/* BEGIN STRATUM 35 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.8(8,"v0,v1","Rule","diedin,v1,v0","inv_0(v0,v1) :- 
   Rule(7),
   diedin(v1,v0).").
in file  [0:0-0:0])_");
rel_40_inv_0_info_8->insert(RamDomain(8),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(17));
}();
/* END STRATUM 35 */
/* BEGIN STRATUM 36 */
[&]() {
SignalHandler::instance()->setMsg(R"_(inv_0.@info.9(9,"v0,v1","Rule","created,v0,v1","inv_0(v0,v1) :- 
   Rule(8),
   created(v0,v1).").
in file  [0:0-0:0])_");
rel_41_inv_0_info_9->insert(RamDomain(9),RamDomain(0),RamDomain(1),RamDomain(18),RamDomain(19));
}();
/* END STRATUM 36 */
/* BEGIN STRATUM 37 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.1(1,"v0,v1","Rule","islocatedin,v0,v1","wasbornin(v0,v1) :- 
   Rule(26),
   islocatedin(v0,v1).").
in file  [0:0-0:0])_");
rel_42_wasbornin_info_1->insert(RamDomain(1),RamDomain(0),RamDomain(1),RamDomain(2),RamDomain(48));
}();
/* END STRATUM 37 */
/* BEGIN STRATUM 38 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.10(10,"v0,v1","Rule","created,v1,v0","wasbornin(v0,v1) :- 
   Rule(35),
   created(v1,v0).").
in file  [0:0-0:0])_");
rel_43_wasbornin_info_10->insert(RamDomain(10),RamDomain(0),RamDomain(1),RamDomain(20),RamDomain(57));
}();
/* END STRATUM 38 */
/* BEGIN STRATUM 39 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.11(11,"v0,v1","Rule","influences,v0,v1","wasbornin(v0,v1) :- 
   Rule(36),
   influences(v0,v1).").
in file  [0:0-0:0])_");
rel_44_wasbornin_info_11->insert(RamDomain(11),RamDomain(0),RamDomain(1),RamDomain(22),RamDomain(58));
}();
/* END STRATUM 39 */
/* BEGIN STRATUM 40 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.12(12,"v0,v1","Rule","influences,v1,v0","wasbornin(v0,v1) :- 
   Rule(37),
   influences(v1,v0).").
in file  [0:0-0:0])_");
rel_45_wasbornin_info_12->insert(RamDomain(12),RamDomain(0),RamDomain(1),RamDomain(24),RamDomain(59));
}();
/* END STRATUM 40 */
/* BEGIN STRATUM 41 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.13(13,"v0,v1","Rule","hasgeonamesid,v0,v1","wasbornin(v0,v1) :- 
   Rule(38),
   hasgeonamesid(v0,v1).").
in file  [0:0-0:0])_");
rel_46_wasbornin_info_13->insert(RamDomain(13),RamDomain(0),RamDomain(1),RamDomain(26),RamDomain(60));
}();
/* END STRATUM 41 */
/* BEGIN STRATUM 42 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.14(14,"v0,v1","Rule","hasgeonamesid,v1,v0","wasbornin(v0,v1) :- 
   Rule(39),
   hasgeonamesid(v1,v0).").
in file  [0:0-0:0])_");
rel_47_wasbornin_info_14->insert(RamDomain(14),RamDomain(0),RamDomain(1),RamDomain(28),RamDomain(61));
}();
/* END STRATUM 42 */
/* BEGIN STRATUM 43 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.15(15,"v0,v1","Rule","haswonprize,v0,v1","wasbornin(v0,v1) :- 
   Rule(40),
   haswonprize(v0,v1).").
in file  [0:0-0:0])_");
rel_48_wasbornin_info_15->insert(RamDomain(15),RamDomain(0),RamDomain(1),RamDomain(30),RamDomain(62));
}();
/* END STRATUM 43 */
/* BEGIN STRATUM 44 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.16(16,"v0,v1","Rule","haswonprize,v1,v0","wasbornin(v0,v1) :- 
   Rule(41),
   haswonprize(v1,v0).").
in file  [0:0-0:0])_");
rel_49_wasbornin_info_16->insert(RamDomain(16),RamDomain(0),RamDomain(1),RamDomain(32),RamDomain(63));
}();
/* END STRATUM 44 */
/* BEGIN STRATUM 45 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.17(17,"v0,v1","Rule","ismarriedto,v0,v1","wasbornin(v0,v1) :- 
   Rule(42),
   ismarriedto(v0,v1).").
in file  [0:0-0:0])_");
rel_50_wasbornin_info_17->insert(RamDomain(17),RamDomain(0),RamDomain(1),RamDomain(34),RamDomain(64));
}();
/* END STRATUM 45 */
/* BEGIN STRATUM 46 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.18(18,"v0,v1","Rule","ismarriedto,v1,v0","wasbornin(v0,v1) :- 
   Rule(43),
   ismarriedto(v1,v0).").
in file  [0:0-0:0])_");
rel_51_wasbornin_info_18->insert(RamDomain(18),RamDomain(0),RamDomain(1),RamDomain(36),RamDomain(65));
}();
/* END STRATUM 46 */
/* BEGIN STRATUM 47 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.19(19,"v0,v1","Rule","participatedin,v0,v1","wasbornin(v0,v1) :- 
   Rule(44),
   participatedin(v0,v1).").
in file  [0:0-0:0])_");
rel_52_wasbornin_info_19->insert(RamDomain(19),RamDomain(0),RamDomain(1),RamDomain(38),RamDomain(66));
}();
/* END STRATUM 47 */
/* BEGIN STRATUM 48 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.2(2,"v0,v1","Rule","islocatedin,v1,v0","wasbornin(v0,v1) :- 
   Rule(27),
   islocatedin(v1,v0).").
in file  [0:0-0:0])_");
rel_53_wasbornin_info_2->insert(RamDomain(2),RamDomain(0),RamDomain(1),RamDomain(4),RamDomain(49));
}();
/* END STRATUM 48 */
/* BEGIN STRATUM 49 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.20(20,"v0,v1","Rule","participatedin,v1,v0","wasbornin(v0,v1) :- 
   Rule(45),
   participatedin(v1,v0).").
in file  [0:0-0:0])_");
rel_54_wasbornin_info_20->insert(RamDomain(20),RamDomain(0),RamDomain(1),RamDomain(40),RamDomain(67));
}();
/* END STRATUM 49 */
/* BEGIN STRATUM 50 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.21(21,"v0,v1","Rule","actedin,v0,v1","wasbornin(v0,v1) :- 
   Rule(46),
   actedin(v0,v1).").
in file  [0:0-0:0])_");
rel_55_wasbornin_info_21->insert(RamDomain(21),RamDomain(0),RamDomain(1),RamDomain(42),RamDomain(68));
}();
/* END STRATUM 50 */
/* BEGIN STRATUM 51 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.22(22,"v0,v1","Rule","actedin,v1,v0","wasbornin(v0,v1) :- 
   Rule(47),
   actedin(v1,v0).").
in file  [0:0-0:0])_");
rel_56_wasbornin_info_22->insert(RamDomain(22),RamDomain(0),RamDomain(1),RamDomain(44),RamDomain(69));
}();
/* END STRATUM 51 */
/* BEGIN STRATUM 52 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.23(23,"v0,v1","Rule","inv_0,v0,v1","wasbornin(v0,v1) :- 
   Rule(50),
   inv_0(v0,v1).").
in file  [0:0-0:0])_");
rel_57_wasbornin_info_23->insert(RamDomain(23),RamDomain(0),RamDomain(1),RamDomain(70),RamDomain(71));
}();
/* END STRATUM 52 */
/* BEGIN STRATUM 53 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.24(24,"v0,v1","Rule","inv_0,v1,v0","wasbornin(v0,v1) :- 
   Rule(51),
   inv_0(v1,v0).").
in file  [0:0-0:0])_");
rel_58_wasbornin_info_24->insert(RamDomain(24),RamDomain(0),RamDomain(1),RamDomain(46),RamDomain(72));
}();
/* END STRATUM 53 */
/* BEGIN STRATUM 54 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.25(25,"v0,v1","Rule","wasbornin,v1,v0","wasbornin(v0,v1) :- 
   Rule(53),
   wasbornin(v1,v0).").
in file  [0:0-0:0])_");
rel_59_wasbornin_info_25->insert(RamDomain(25),RamDomain(0),RamDomain(1),RamDomain(73),RamDomain(74));
}();
/* END STRATUM 54 */
/* BEGIN STRATUM 55 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.3(3,"v0,v1","Rule","directed,v0,v1","wasbornin(v0,v1) :- 
   Rule(28),
   directed(v0,v1).").
in file  [0:0-0:0])_");
rel_60_wasbornin_info_3->insert(RamDomain(3),RamDomain(0),RamDomain(1),RamDomain(6),RamDomain(50));
}();
/* END STRATUM 55 */
/* BEGIN STRATUM 56 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.4(4,"v0,v1","Rule","directed,v1,v0","wasbornin(v0,v1) :- 
   Rule(29),
   directed(v1,v0).").
in file  [0:0-0:0])_");
rel_61_wasbornin_info_4->insert(RamDomain(4),RamDomain(0),RamDomain(1),RamDomain(8),RamDomain(51));
}();
/* END STRATUM 56 */
/* BEGIN STRATUM 57 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.5(5,"v0,v1","Rule","haschild,v0,v1","wasbornin(v0,v1) :- 
   Rule(30),
   haschild(v0,v1).").
in file  [0:0-0:0])_");
rel_62_wasbornin_info_5->insert(RamDomain(5),RamDomain(0),RamDomain(1),RamDomain(10),RamDomain(52));
}();
/* END STRATUM 57 */
/* BEGIN STRATUM 58 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.6(6,"v0,v1","Rule","haschild,v1,v0","wasbornin(v0,v1) :- 
   Rule(31),
   haschild(v1,v0).").
in file  [0:0-0:0])_");
rel_63_wasbornin_info_6->insert(RamDomain(6),RamDomain(0),RamDomain(1),RamDomain(12),RamDomain(53));
}();
/* END STRATUM 58 */
/* BEGIN STRATUM 59 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.7(7,"v0,v1","Rule","diedin,v0,v1","wasbornin(v0,v1) :- 
   Rule(32),
   diedin(v0,v1).").
in file  [0:0-0:0])_");
rel_64_wasbornin_info_7->insert(RamDomain(7),RamDomain(0),RamDomain(1),RamDomain(14),RamDomain(54));
}();
/* END STRATUM 59 */
/* BEGIN STRATUM 60 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.8(8,"v0,v1","Rule","diedin,v1,v0","wasbornin(v0,v1) :- 
   Rule(33),
   diedin(v1,v0).").
in file  [0:0-0:0])_");
rel_65_wasbornin_info_8->insert(RamDomain(8),RamDomain(0),RamDomain(1),RamDomain(16),RamDomain(55));
}();
/* END STRATUM 60 */
/* BEGIN STRATUM 61 */
[&]() {
SignalHandler::instance()->setMsg(R"_(wasbornin.@info.9(9,"v0,v1","Rule","created,v0,v1","wasbornin(v0,v1) :- 
   Rule(34),
   created(v0,v1).").
in file  [0:0-0:0])_");
rel_66_wasbornin_info_9->insert(RamDomain(9),RamDomain(0),RamDomain(1),RamDomain(18),RamDomain(56));
}();
/* END STRATUM 61 */

// -- relation hint statistics --
if(isHintsProfilingEnabled()) {
std::cout << " -- Operation Hint Statistics --\n";
std::cout << "Relation rel_1_Rule:\n";
rel_1_Rule->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_2_actedin:\n";
rel_2_actedin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_3_created:\n";
rel_3_created->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_4_diedin:\n";
rel_4_diedin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_5_directed:\n";
rel_5_directed->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_6_haschild:\n";
rel_6_haschild->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_7_hasgeonamesid:\n";
rel_7_hasgeonamesid->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_8_haswonprize:\n";
rel_8_haswonprize->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_9_influences:\n";
rel_9_influences->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_10_islocatedin:\n";
rel_10_islocatedin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_11_ismarriedto:\n";
rel_11_ismarriedto->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_12_participatedin:\n";
rel_12_participatedin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_13_inv_0:\n";
rel_13_inv_0->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_14_delta_inv_0:\n";
rel_14_delta_inv_0->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_15_new_inv_0:\n";
rel_15_new_inv_0->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_16_wasbornin:\n";
rel_16_wasbornin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_17_delta_wasbornin:\n";
rel_17_delta_wasbornin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_18_new_wasbornin:\n";
rel_18_new_wasbornin->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_19_inv_0_info_1:\n";
rel_19_inv_0_info_1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_20_inv_0_info_10:\n";
rel_20_inv_0_info_10->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_21_inv_0_info_11:\n";
rel_21_inv_0_info_11->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_22_inv_0_info_12:\n";
rel_22_inv_0_info_12->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_23_inv_0_info_13:\n";
rel_23_inv_0_info_13->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_24_inv_0_info_14:\n";
rel_24_inv_0_info_14->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_25_inv_0_info_15:\n";
rel_25_inv_0_info_15->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_26_inv_0_info_16:\n";
rel_26_inv_0_info_16->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_27_inv_0_info_17:\n";
rel_27_inv_0_info_17->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_28_inv_0_info_18:\n";
rel_28_inv_0_info_18->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_29_inv_0_info_19:\n";
rel_29_inv_0_info_19->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_30_inv_0_info_2:\n";
rel_30_inv_0_info_2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_31_inv_0_info_20:\n";
rel_31_inv_0_info_20->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_32_inv_0_info_21:\n";
rel_32_inv_0_info_21->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_33_inv_0_info_22:\n";
rel_33_inv_0_info_22->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_34_inv_0_info_23:\n";
rel_34_inv_0_info_23->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_35_inv_0_info_3:\n";
rel_35_inv_0_info_3->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_36_inv_0_info_4:\n";
rel_36_inv_0_info_4->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_37_inv_0_info_5:\n";
rel_37_inv_0_info_5->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_38_inv_0_info_6:\n";
rel_38_inv_0_info_6->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_39_inv_0_info_7:\n";
rel_39_inv_0_info_7->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_40_inv_0_info_8:\n";
rel_40_inv_0_info_8->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_41_inv_0_info_9:\n";
rel_41_inv_0_info_9->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_42_wasbornin_info_1:\n";
rel_42_wasbornin_info_1->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_43_wasbornin_info_10:\n";
rel_43_wasbornin_info_10->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_44_wasbornin_info_11:\n";
rel_44_wasbornin_info_11->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_45_wasbornin_info_12:\n";
rel_45_wasbornin_info_12->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_46_wasbornin_info_13:\n";
rel_46_wasbornin_info_13->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_47_wasbornin_info_14:\n";
rel_47_wasbornin_info_14->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_48_wasbornin_info_15:\n";
rel_48_wasbornin_info_15->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_49_wasbornin_info_16:\n";
rel_49_wasbornin_info_16->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_50_wasbornin_info_17:\n";
rel_50_wasbornin_info_17->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_51_wasbornin_info_18:\n";
rel_51_wasbornin_info_18->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_52_wasbornin_info_19:\n";
rel_52_wasbornin_info_19->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_53_wasbornin_info_2:\n";
rel_53_wasbornin_info_2->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_54_wasbornin_info_20:\n";
rel_54_wasbornin_info_20->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_55_wasbornin_info_21:\n";
rel_55_wasbornin_info_21->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_56_wasbornin_info_22:\n";
rel_56_wasbornin_info_22->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_57_wasbornin_info_23:\n";
rel_57_wasbornin_info_23->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_58_wasbornin_info_24:\n";
rel_58_wasbornin_info_24->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_59_wasbornin_info_25:\n";
rel_59_wasbornin_info_25->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_60_wasbornin_info_3:\n";
rel_60_wasbornin_info_3->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_61_wasbornin_info_4:\n";
rel_61_wasbornin_info_4->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_62_wasbornin_info_5:\n";
rel_62_wasbornin_info_5->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_63_wasbornin_info_6:\n";
rel_63_wasbornin_info_6->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_64_wasbornin_info_7:\n";
rel_64_wasbornin_info_7->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_65_wasbornin_info_8:\n";
rel_65_wasbornin_info_8->printHintStatistics(std::cout,"  ");
std::cout << "\n";
std::cout << "Relation rel_66_wasbornin_info_9:\n";
rel_66_wasbornin_info_9->printHintStatistics(std::cout,"  ");
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
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_13_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","v0\tv1"},{"filename","./wasbornin.csv"},{"name","wasbornin"}});
if (!outputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = outputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_16_wasbornin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void loadAll(std::string inputDirectory = ".") override {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./Rule.facts"},{"name","Rule"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({0,0,0}), symTable, ioDirectives, true)->readAll(*rel_1_Rule);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./actedin.facts"},{"name","actedin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_2_actedin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./created.facts"},{"name","created"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_3_created);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./diedin.facts"},{"name","diedin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_4_diedin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./directed.facts"},{"name","directed"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_5_directed);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./haschild.facts"},{"name","haschild"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_6_haschild);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./hasgeonamesid.facts"},{"name","hasgeonamesid"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_7_hasgeonamesid);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./haswonprize.facts"},{"name","haswonprize"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_8_haswonprize);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./influences.facts"},{"name","influences"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_9_influences);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./islocatedin.facts"},{"name","islocatedin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_10_islocatedin);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./ismarriedto.facts"},{"name","ismarriedto"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_11_ismarriedto);
} catch (std::exception& e) {std::cerr << "Error loading data: " << e.what() << '\n';}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"filename","./participatedin.facts"},{"name","participatedin"}});
if (!inputDirectory.empty() && directiveMap["IO"] == "file" && directiveMap["filename"].front() != '/') {directiveMap["filename"] = inputDirectory + "/" + directiveMap["filename"];}
IODirectives ioDirectives(directiveMap);
IOSystem::getInstance().getReader(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->readAll(*rel_12_participatedin);
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
ioDirectives.setRelationName("rel_2_actedin");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_2_actedin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_3_created");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_3_created);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_4_diedin");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_4_diedin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_5_directed");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_5_directed);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_6_haschild");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_6_haschild);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_7_hasgeonamesid");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_7_hasgeonamesid);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_8_haswonprize");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_8_haswonprize);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_9_influences");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_9_influences);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_10_islocatedin");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_10_islocatedin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_11_ismarriedto");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_11_ismarriedto);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_12_participatedin");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_12_participatedin);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
public:
void dumpOutputs(std::ostream& out = std::cout) override {
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_13_inv_0");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_13_inv_0);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {IODirectives ioDirectives;
ioDirectives.setIOType("stdout");
ioDirectives.setRelationName("rel_16_wasbornin");
IOSystem::getInstance().getWriter(std::vector<bool>({1,1,0,0}), symTable, ioDirectives, true)->writeAll(*rel_16_wasbornin);
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
if (name == "inv_0_2_negation_subproof") {
subproof_30(args, ret, err);
}
if (name == "inv_0_2_subproof") {
subproof_31(args, ret, err);
}
if (name == "inv_0_3_negation_subproof") {
subproof_32(args, ret, err);
}
if (name == "inv_0_3_subproof") {
subproof_33(args, ret, err);
}
if (name == "inv_0_4_negation_subproof") {
subproof_34(args, ret, err);
}
if (name == "inv_0_4_subproof") {
subproof_35(args, ret, err);
}
if (name == "inv_0_5_negation_subproof") {
subproof_36(args, ret, err);
}
if (name == "inv_0_5_subproof") {
subproof_37(args, ret, err);
}
if (name == "inv_0_6_negation_subproof") {
subproof_38(args, ret, err);
}
if (name == "inv_0_6_subproof") {
subproof_39(args, ret, err);
}
if (name == "inv_0_7_negation_subproof") {
subproof_40(args, ret, err);
}
if (name == "inv_0_7_subproof") {
subproof_41(args, ret, err);
}
if (name == "inv_0_8_negation_subproof") {
subproof_42(args, ret, err);
}
if (name == "inv_0_8_subproof") {
subproof_43(args, ret, err);
}
if (name == "inv_0_9_negation_subproof") {
subproof_44(args, ret, err);
}
if (name == "inv_0_9_subproof") {
subproof_45(args, ret, err);
}
if (name == "wasbornin_10_negation_subproof") {
subproof_46(args, ret, err);
}
if (name == "wasbornin_10_subproof") {
subproof_47(args, ret, err);
}
if (name == "wasbornin_11_negation_subproof") {
subproof_48(args, ret, err);
}
if (name == "wasbornin_11_subproof") {
subproof_49(args, ret, err);
}
if (name == "wasbornin_12_negation_subproof") {
subproof_50(args, ret, err);
}
if (name == "wasbornin_12_subproof") {
subproof_51(args, ret, err);
}
if (name == "wasbornin_13_negation_subproof") {
subproof_52(args, ret, err);
}
if (name == "wasbornin_13_subproof") {
subproof_53(args, ret, err);
}
if (name == "wasbornin_14_negation_subproof") {
subproof_54(args, ret, err);
}
if (name == "wasbornin_14_subproof") {
subproof_55(args, ret, err);
}
if (name == "wasbornin_15_negation_subproof") {
subproof_56(args, ret, err);
}
if (name == "wasbornin_15_subproof") {
subproof_57(args, ret, err);
}
if (name == "wasbornin_16_negation_subproof") {
subproof_58(args, ret, err);
}
if (name == "wasbornin_16_subproof") {
subproof_59(args, ret, err);
}
if (name == "wasbornin_17_negation_subproof") {
subproof_60(args, ret, err);
}
if (name == "wasbornin_17_subproof") {
subproof_61(args, ret, err);
}
if (name == "wasbornin_18_negation_subproof") {
subproof_62(args, ret, err);
}
if (name == "wasbornin_18_subproof") {
subproof_63(args, ret, err);
}
if (name == "wasbornin_19_negation_subproof") {
subproof_64(args, ret, err);
}
if (name == "wasbornin_19_subproof") {
subproof_65(args, ret, err);
}
if (name == "wasbornin_1_negation_subproof") {
subproof_66(args, ret, err);
}
if (name == "wasbornin_1_subproof") {
subproof_67(args, ret, err);
}
if (name == "wasbornin_20_negation_subproof") {
subproof_68(args, ret, err);
}
if (name == "wasbornin_20_subproof") {
subproof_69(args, ret, err);
}
if (name == "wasbornin_21_negation_subproof") {
subproof_70(args, ret, err);
}
if (name == "wasbornin_21_subproof") {
subproof_71(args, ret, err);
}
if (name == "wasbornin_22_negation_subproof") {
subproof_72(args, ret, err);
}
if (name == "wasbornin_22_subproof") {
subproof_73(args, ret, err);
}
if (name == "wasbornin_23_negation_subproof") {
subproof_74(args, ret, err);
}
if (name == "wasbornin_23_subproof") {
subproof_75(args, ret, err);
}
if (name == "wasbornin_24_negation_subproof") {
subproof_76(args, ret, err);
}
if (name == "wasbornin_24_subproof") {
subproof_77(args, ret, err);
}
if (name == "wasbornin_25_negation_subproof") {
subproof_78(args, ret, err);
}
if (name == "wasbornin_25_subproof") {
subproof_79(args, ret, err);
}
if (name == "wasbornin_2_negation_subproof") {
subproof_80(args, ret, err);
}
if (name == "wasbornin_2_subproof") {
subproof_81(args, ret, err);
}
if (name == "wasbornin_3_negation_subproof") {
subproof_82(args, ret, err);
}
if (name == "wasbornin_3_subproof") {
subproof_83(args, ret, err);
}
if (name == "wasbornin_4_negation_subproof") {
subproof_84(args, ret, err);
}
if (name == "wasbornin_4_subproof") {
subproof_85(args, ret, err);
}
if (name == "wasbornin_5_negation_subproof") {
subproof_86(args, ret, err);
}
if (name == "wasbornin_5_subproof") {
subproof_87(args, ret, err);
}
if (name == "wasbornin_6_negation_subproof") {
subproof_88(args, ret, err);
}
if (name == "wasbornin_6_subproof") {
subproof_89(args, ret, err);
}
if (name == "wasbornin_7_negation_subproof") {
subproof_90(args, ret, err);
}
if (name == "wasbornin_7_subproof") {
subproof_91(args, ret, err);
}
if (name == "wasbornin_8_negation_subproof") {
subproof_92(args, ret, err);
}
if (name == "wasbornin_8_subproof") {
subproof_93(args, ret, err);
}
if (name == "wasbornin_9_negation_subproof") {
subproof_94(args, ret, err);
}
if (name == "wasbornin_9_subproof") {
subproof_95(args, ret, err);
}
}
void subproof_0(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(9),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
if(!rel_3_created->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_created_op_ctxt)).empty()) {
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
void subproof_1(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_created->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(9),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_created->equalRange_3(key,READ_OP_CONTEXT(rel_3_created_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_2(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(10),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_9_influences_op_ctxt,rel_9_influences->createContext());
if(!rel_9_influences->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_9_influences_op_ctxt)).empty()) {
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
if(!(rel_9_influences->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(10),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_9_influences_op_ctxt,rel_9_influences->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_9_influences->equalRange_3(key,READ_OP_CONTEXT(rel_9_influences_op_ctxt));
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
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(11),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_9_influences_op_ctxt,rel_9_influences->createContext());
if(!rel_9_influences->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_9_influences_op_ctxt)).empty()) {
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
void subproof_5(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_9_influences->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(11),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_9_influences_op_ctxt,rel_9_influences->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_9_influences->equalRange_3(key,READ_OP_CONTEXT(rel_9_influences_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_6(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(12),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt,rel_7_hasgeonamesid->createContext());
if(!rel_7_hasgeonamesid->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt)).empty()) {
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
void subproof_7(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_hasgeonamesid->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(12),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt,rel_7_hasgeonamesid->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_7_hasgeonamesid->equalRange_3(key,READ_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_8(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(13),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt,rel_7_hasgeonamesid->createContext());
if(!rel_7_hasgeonamesid->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt)).empty()) {
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
void subproof_9(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_hasgeonamesid->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(13),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt,rel_7_hasgeonamesid->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_7_hasgeonamesid->equalRange_3(key,READ_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_10(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(14),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_8_haswonprize_op_ctxt,rel_8_haswonprize->createContext());
if(!rel_8_haswonprize->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_8_haswonprize_op_ctxt)).empty()) {
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
void subproof_11(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_8_haswonprize->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(14),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_haswonprize_op_ctxt,rel_8_haswonprize->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_8_haswonprize->equalRange_3(key,READ_OP_CONTEXT(rel_8_haswonprize_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_12(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(15),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_8_haswonprize_op_ctxt,rel_8_haswonprize->createContext());
if(!rel_8_haswonprize->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_8_haswonprize_op_ctxt)).empty()) {
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
void subproof_13(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_8_haswonprize->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(15),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_haswonprize_op_ctxt,rel_8_haswonprize->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_8_haswonprize->equalRange_3(key,READ_OP_CONTEXT(rel_8_haswonprize_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_14(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(16),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_11_ismarriedto_op_ctxt,rel_11_ismarriedto->createContext());
if(!rel_11_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_11_ismarriedto_op_ctxt)).empty()) {
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
void subproof_15(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_11_ismarriedto->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(16),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_11_ismarriedto_op_ctxt,rel_11_ismarriedto->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_11_ismarriedto->equalRange_3(key,READ_OP_CONTEXT(rel_11_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_16(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(17),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_11_ismarriedto_op_ctxt,rel_11_ismarriedto->createContext());
if(!rel_11_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_11_ismarriedto_op_ctxt)).empty()) {
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
void subproof_17(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_11_ismarriedto->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(17),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_11_ismarriedto_op_ctxt,rel_11_ismarriedto->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_11_ismarriedto->equalRange_3(key,READ_OP_CONTEXT(rel_11_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_18(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(18),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(18));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_12_participatedin_op_ctxt,rel_12_participatedin->createContext());
if(!rel_12_participatedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_12_participatedin_op_ctxt)).empty()) {
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
if(!(rel_12_participatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(18),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_12_participatedin_op_ctxt,rel_12_participatedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_12_participatedin->equalRange_3(key,READ_OP_CONTEXT(rel_12_participatedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(18));
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
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(0),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_10_islocatedin_op_ctxt,rel_10_islocatedin->createContext());
if(!rel_10_islocatedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_10_islocatedin_op_ctxt)).empty()) {
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
if(!(rel_10_islocatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(0),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_10_islocatedin_op_ctxt,rel_10_islocatedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_10_islocatedin->equalRange_3(key,READ_OP_CONTEXT(rel_10_islocatedin_op_ctxt));
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
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(19),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(19));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_12_participatedin_op_ctxt,rel_12_participatedin->createContext());
if(!rel_12_participatedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_12_participatedin_op_ctxt)).empty()) {
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
void subproof_23(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_12_participatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(19),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_12_participatedin_op_ctxt,rel_12_participatedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_12_participatedin->equalRange_3(key,READ_OP_CONTEXT(rel_12_participatedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(19));
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
void subproof_24(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(20),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_2_actedin_op_ctxt,rel_2_actedin->createContext());
if(!rel_2_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_2_actedin_op_ctxt)).empty()) {
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
void subproof_25(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_2_actedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(20),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_2_actedin_op_ctxt,rel_2_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_2_actedin->equalRange_3(key,READ_OP_CONTEXT(rel_2_actedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_26(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(21),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_2_actedin_op_ctxt,rel_2_actedin->createContext());
if(!rel_2_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_2_actedin_op_ctxt)).empty()) {
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
void subproof_27(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_2_actedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(21),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_2_actedin_op_ctxt,rel_2_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_2_actedin->equalRange_3(key,READ_OP_CONTEXT(rel_2_actedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_28(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(25),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
if(!rel_13_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_13_inv_0_op_ctxt)).empty()) {
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
void subproof_29(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_13_inv_0->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(25),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_13_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_30(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(1),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_10_islocatedin_op_ctxt,rel_10_islocatedin->createContext());
if(!rel_10_islocatedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_10_islocatedin_op_ctxt)).empty()) {
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
void subproof_31(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_10_islocatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(1),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_10_islocatedin_op_ctxt,rel_10_islocatedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_10_islocatedin->equalRange_3(key,READ_OP_CONTEXT(rel_10_islocatedin_op_ctxt));
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
void subproof_32(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(2),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_directed_op_ctxt,rel_5_directed->createContext());
if(!rel_5_directed->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_5_directed_op_ctxt)).empty()) {
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
void subproof_33(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_directed->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(2),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_directed_op_ctxt,rel_5_directed->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_5_directed->equalRange_3(key,READ_OP_CONTEXT(rel_5_directed_op_ctxt));
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
void subproof_34(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(3),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_directed_op_ctxt,rel_5_directed->createContext());
if(!rel_5_directed->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_directed_op_ctxt)).empty()) {
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
if(!(rel_5_directed->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(3),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_directed_op_ctxt,rel_5_directed->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_5_directed->equalRange_3(key,READ_OP_CONTEXT(rel_5_directed_op_ctxt));
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
void subproof_36(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(4),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(4));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_6_haschild_op_ctxt,rel_6_haschild->createContext());
if(!rel_6_haschild->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_6_haschild_op_ctxt)).empty()) {
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
void subproof_37(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_6_haschild->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(4),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_6_haschild_op_ctxt,rel_6_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_6_haschild->equalRange_3(key,READ_OP_CONTEXT(rel_6_haschild_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(4));
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
void subproof_38(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(5),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_6_haschild_op_ctxt,rel_6_haschild->createContext());
if(!rel_6_haschild->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_6_haschild_op_ctxt)).empty()) {
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
void subproof_39(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_6_haschild->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(5),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_6_haschild_op_ctxt,rel_6_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_6_haschild->equalRange_3(key,READ_OP_CONTEXT(rel_6_haschild_op_ctxt));
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
void subproof_40(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(6),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_diedin_op_ctxt,rel_4_diedin->createContext());
if(!rel_4_diedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_diedin_op_ctxt)).empty()) {
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
void subproof_41(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_diedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(6),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_diedin_op_ctxt,rel_4_diedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_4_diedin->equalRange_3(key,READ_OP_CONTEXT(rel_4_diedin_op_ctxt));
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
void subproof_42(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(7),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_diedin_op_ctxt,rel_4_diedin->createContext());
if(!rel_4_diedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_diedin_op_ctxt)).empty()) {
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
if(!(rel_4_diedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(7),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_diedin_op_ctxt,rel_4_diedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_4_diedin->equalRange_3(key,READ_OP_CONTEXT(rel_4_diedin_op_ctxt));
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
void subproof_44(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(8),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
void subproof_45(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_created->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(8),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
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
void subproof_46(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(35),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
if(!rel_3_created->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_3_created_op_ctxt)).empty()) {
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
void subproof_47(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_created->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(35),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_3_created_op_ctxt,rel_3_created->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_3_created->equalRange_3(key,READ_OP_CONTEXT(rel_3_created_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_48(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(36),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_9_influences_op_ctxt,rel_9_influences->createContext());
if(!rel_9_influences->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_9_influences_op_ctxt)).empty()) {
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
void subproof_49(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_9_influences->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(36),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_9_influences_op_ctxt,rel_9_influences->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_9_influences->equalRange_3(key,READ_OP_CONTEXT(rel_9_influences_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_50(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(37),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_9_influences_op_ctxt,rel_9_influences->createContext());
if(!rel_9_influences->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_9_influences_op_ctxt)).empty()) {
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
void subproof_51(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_9_influences->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(37),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_9_influences_op_ctxt,rel_9_influences->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_9_influences->equalRange_3(key,READ_OP_CONTEXT(rel_9_influences_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_52(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(38),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt,rel_7_hasgeonamesid->createContext());
if(!rel_7_hasgeonamesid->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt)).empty()) {
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
void subproof_53(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_7_hasgeonamesid->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(38),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt,rel_7_hasgeonamesid->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_7_hasgeonamesid->equalRange_3(key,READ_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_54(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(39),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt,rel_7_hasgeonamesid->createContext());
if(!rel_7_hasgeonamesid->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt)).empty()) {
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
if(!(rel_7_hasgeonamesid->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(39),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt,rel_7_hasgeonamesid->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_7_hasgeonamesid->equalRange_3(key,READ_OP_CONTEXT(rel_7_hasgeonamesid_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(40),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_8_haswonprize_op_ctxt,rel_8_haswonprize->createContext());
if(!rel_8_haswonprize->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_8_haswonprize_op_ctxt)).empty()) {
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
if(!(rel_8_haswonprize->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(40),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_haswonprize_op_ctxt,rel_8_haswonprize->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_8_haswonprize->equalRange_3(key,READ_OP_CONTEXT(rel_8_haswonprize_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(41),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_8_haswonprize_op_ctxt,rel_8_haswonprize->createContext());
if(!rel_8_haswonprize->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_8_haswonprize_op_ctxt)).empty()) {
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
void subproof_59(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_8_haswonprize->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(41),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_8_haswonprize_op_ctxt,rel_8_haswonprize->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_8_haswonprize->equalRange_3(key,READ_OP_CONTEXT(rel_8_haswonprize_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_60(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(42),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(42));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_11_ismarriedto_op_ctxt,rel_11_ismarriedto->createContext());
if(!rel_11_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_11_ismarriedto_op_ctxt)).empty()) {
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
void subproof_61(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_11_ismarriedto->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(42),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_11_ismarriedto_op_ctxt,rel_11_ismarriedto->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_11_ismarriedto->equalRange_3(key,READ_OP_CONTEXT(rel_11_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(42));
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
void subproof_62(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(43),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(43));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_11_ismarriedto_op_ctxt,rel_11_ismarriedto->createContext());
if(!rel_11_ismarriedto->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_11_ismarriedto_op_ctxt)).empty()) {
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
void subproof_63(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_11_ismarriedto->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(43),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_11_ismarriedto_op_ctxt,rel_11_ismarriedto->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_11_ismarriedto->equalRange_3(key,READ_OP_CONTEXT(rel_11_ismarriedto_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(43));
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
void subproof_64(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(44),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(44));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_12_participatedin_op_ctxt,rel_12_participatedin->createContext());
if(!rel_12_participatedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_12_participatedin_op_ctxt)).empty()) {
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
if(!(rel_12_participatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(44),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_12_participatedin_op_ctxt,rel_12_participatedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_12_participatedin->equalRange_3(key,READ_OP_CONTEXT(rel_12_participatedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(44));
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
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(26),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_10_islocatedin_op_ctxt,rel_10_islocatedin->createContext());
if(!rel_10_islocatedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_10_islocatedin_op_ctxt)).empty()) {
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
void subproof_67(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_10_islocatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(26),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_10_islocatedin_op_ctxt,rel_10_islocatedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_10_islocatedin->equalRange_3(key,READ_OP_CONTEXT(rel_10_islocatedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_68(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(45),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_12_participatedin_op_ctxt,rel_12_participatedin->createContext());
if(!rel_12_participatedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_12_participatedin_op_ctxt)).empty()) {
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
void subproof_69(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_12_participatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(45),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_12_participatedin_op_ctxt,rel_12_participatedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_12_participatedin->equalRange_3(key,READ_OP_CONTEXT(rel_12_participatedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_70(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(46),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_2_actedin_op_ctxt,rel_2_actedin->createContext());
if(!rel_2_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_2_actedin_op_ctxt)).empty()) {
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
void subproof_71(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_2_actedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(46),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_2_actedin_op_ctxt,rel_2_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_2_actedin->equalRange_3(key,READ_OP_CONTEXT(rel_2_actedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_72(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(47),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(47));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_2_actedin_op_ctxt,rel_2_actedin->createContext());
if(!rel_2_actedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_2_actedin_op_ctxt)).empty()) {
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
void subproof_73(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_2_actedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(47),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_2_actedin_op_ctxt,rel_2_actedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_2_actedin->equalRange_3(key,READ_OP_CONTEXT(rel_2_actedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(47));
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
void subproof_74(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(50),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
if(!rel_13_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_13_inv_0_op_ctxt)).empty()) {
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
void subproof_75(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_13_inv_0->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(50),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_13_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_76(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(51),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(51));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
if(!rel_13_inv_0->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_13_inv_0_op_ctxt)).empty()) {
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
void subproof_77(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_13_inv_0->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(51),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_13_inv_0_op_ctxt,rel_13_inv_0->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_13_inv_0->equalRange_3(key,READ_OP_CONTEXT(rel_13_inv_0_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(51));
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
void subproof_78(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(53),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
if(!rel_16_wasbornin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt)).empty()) {
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
void subproof_79(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_16_wasbornin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(53),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_16_wasbornin_op_ctxt,rel_16_wasbornin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_16_wasbornin->equalRange_3(key,READ_OP_CONTEXT(rel_16_wasbornin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_80(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(27),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(27));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_10_islocatedin_op_ctxt,rel_10_islocatedin->createContext());
if(!rel_10_islocatedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_10_islocatedin_op_ctxt)).empty()) {
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
void subproof_81(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_10_islocatedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(27),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_10_islocatedin_op_ctxt,rel_10_islocatedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_10_islocatedin->equalRange_3(key,READ_OP_CONTEXT(rel_10_islocatedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(27));
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
void subproof_82(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(28),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(28));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_5_directed_op_ctxt,rel_5_directed->createContext());
if(!rel_5_directed->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_5_directed_op_ctxt)).empty()) {
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
void subproof_83(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_directed->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(28),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_directed_op_ctxt,rel_5_directed->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_5_directed->equalRange_3(key,READ_OP_CONTEXT(rel_5_directed_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(28));
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
void subproof_84(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(29),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_5_directed_op_ctxt,rel_5_directed->createContext());
if(!rel_5_directed->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_5_directed_op_ctxt)).empty()) {
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
void subproof_85(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_5_directed->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(29),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_5_directed_op_ctxt,rel_5_directed->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_5_directed->equalRange_3(key,READ_OP_CONTEXT(rel_5_directed_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_86(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(30),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(30));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_6_haschild_op_ctxt,rel_6_haschild->createContext());
if(!rel_6_haschild->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_6_haschild_op_ctxt)).empty()) {
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
void subproof_87(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_6_haschild->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(30),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_6_haschild_op_ctxt,rel_6_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_6_haschild->equalRange_3(key,READ_OP_CONTEXT(rel_6_haschild_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(30));
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
void subproof_88(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(31),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_6_haschild_op_ctxt,rel_6_haschild->createContext());
if(!rel_6_haschild->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_6_haschild_op_ctxt)).empty()) {
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
if(!(rel_6_haschild->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(31),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_6_haschild_op_ctxt,rel_6_haschild->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_6_haschild->equalRange_3(key,READ_OP_CONTEXT(rel_6_haschild_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(32),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
CREATE_OP_CONTEXT(rel_4_diedin_op_ctxt,rel_4_diedin->createContext());
if(!rel_4_diedin->equalRange_3(Tuple<RamDomain,4>({{(args)[0],(args)[1],0,0}}),READ_OP_CONTEXT(rel_4_diedin_op_ctxt)).empty()) {
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
void subproof_91(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_diedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(32),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_diedin_op_ctxt,rel_4_diedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[0],(args)[1],0,0}});
auto range = rel_4_diedin->equalRange_3(key,READ_OP_CONTEXT(rel_4_diedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
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
void subproof_92(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(33),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(0));
err.push_back(false);
}
}
();[&](){
std::lock_guard<std::mutex> guard(lock);
ret.push_back(0);
err.push_back(true);
ret.push_back(RamDomain(33));
err.push_back(false);
}
();[&](){
CREATE_OP_CONTEXT(rel_4_diedin_op_ctxt,rel_4_diedin->createContext());
if(!rel_4_diedin->equalRange_3(Tuple<RamDomain,4>({{(args)[1],(args)[0],0,0}}),READ_OP_CONTEXT(rel_4_diedin_op_ctxt)).empty()) {
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
void subproof_93(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_4_diedin->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(33),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
CREATE_OP_CONTEXT(rel_4_diedin_op_ctxt,rel_4_diedin->createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) { 
try{
for(const auto& env0 : *it) {
if( ((env0[2]) < ((args)[2]))) {
const Tuple<RamDomain,4> key({{(args)[1],(args)[0],0,0}});
auto range = rel_4_diedin->equalRange_3(key,READ_OP_CONTEXT(rel_4_diedin_op_ctxt));
for(const auto& env1 : range) {
if( ((env1[3]) < ((args)[2]))) {
std::lock_guard<std::mutex> guard(lock);
ret.push_back(RamDomain(33));
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
void subproof_94(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
[&](){
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
if(!rel_1_Rule->equalRange_1(Tuple<RamDomain,3>({{RamDomain(34),0,0}}),READ_OP_CONTEXT(rel_1_Rule_op_ctxt)).empty()) {
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
void subproof_95(const std::vector<RamDomain>& args, std::vector<RamDomain>& ret, std::vector<bool>& err) {
std::mutex lock;
if(!(rel_3_created->empty()) && !(rel_1_Rule->empty())) {
[&](){
const Tuple<RamDomain,3> key({{RamDomain(34),0,0}});
auto range = rel_1_Rule->equalRange_1(key);
auto part = range.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_1_Rule_op_ctxt,rel_1_Rule->createContext());
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
64,
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
