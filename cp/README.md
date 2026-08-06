# cp/

Competitive programming inside the same knowledge base as DSA — not a separate project. See the [root README](../README.md) for the full repository philosophy.

---

## Why CP lives here

CP exposes me to algorithms and mathematical thinking that rarely show up in interview prep on its own, and sharpens implementation speed under pressure. Anything learned here that generalizes feeds back into `notes/patterns/` — a Codeforces Div 2 D and a LeetCode Hard are often the same pattern in a different constraint set.

---

## Structure

| Folder | Purpose |
|---|---|
| `codeforces/` | Solved CF problems, organized by round |
| `codechef/` | Solved CC problems, organized by contest type |
| `editorials/` | Short writeups on contest problems that generalized into a pattern |
| `templates/` | Competitive-only constructs — sqrt decomposition, persistent structures, anything I wouldn't hand-write in an interview |
| `dsu/`, `fenwick-tree/`, `graph/`, `lazy-propagation/`, `lca/`, `maths/`, `matrix-exponentiation/`, `mo-algo/`, `prime-sieve/`, `segment-tree/`, `stack-queues-pq/`, `string/`, `trees/`, `trie/` | Topic-specific templates and reference implementations for CP-flavored problems |

**`cp/templates/` vs top-level `templates/`:** top-level `templates/` is interview-clean. `cp/templates/` holds things I'd never use in an interview setting — heavier or more specialized constructs.

**`cp/graph/` vs top-level `graph/`:** top-level `graph/` covers BFS/DFS/Dijkstra/topo-sort/Union-Find as used in interviews. `cp/graph/` covers CP-specific additions — bridges/articulation points, 2-SAT, heavy-light decomposition, and similar.

---

## Editorials

Entries in `editorials/` are short — the idea in a few sentences, not a full walkthrough. If the idea generalizes beyond the one problem, it gets a one-line cross-reference to the relevant file in `../notes/patterns/`.

---

## Mistakes

CP-specific bugs go into the single top-level `../mistakes/` log, not a separate one here — tagged CF/CC where useful. One log beats a fragmented one.