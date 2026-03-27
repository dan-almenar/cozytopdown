# 🐾 Petal & Paws

A cozy, kid-friendly top-down game where you wander through an open field caring for little animals.

---

## About

In Petal & Paws, you roam a peaceful field collecting fruits and hearts, then use them to heal and comfort the animals you meet along the way. The goal is simple: keep as many animals happy and loved as possible.

There are no timers, no game-overs, no pressure — just a calm world to explore at your own pace.

---

## Gameplay

### The Player
- Moves freely across an open field
- Movement speed slowly decays over time — the longer you wander without eating, the slower you get
- Eating food restores speed; resting (idling) does too, but much more slowly

### Resources
Scattered throughout the field, two kinds of pickups can be found:

- 🍎 **Fruit** — Feed it to an animal to heal it, or eat it yourself to recover your speed
- ❤️ **Heart** — Give it to a Happy (or Loving) animal to show it some extra affection

### Animals
Animals are found throughout the field and each one has an internal state that changes over time:

| State | Color Tint | Notes |
|-------|------------|-------|
| 😔 Sick | Lime green | Needs food; decays quickly |
| 🙂 Healthy | None (natural) | Stable but still declining |
| 😊 Happy | Golden yellow | Decays slowly; ready to receive love |
| 🥰 Loving | Purple | Peak state; decays slowest of all |

Animal states decay on their own — higher states last longer, lower states fade faster. It's up to you to keep them cared for.

### Interactions
- **Feed** an animal (any state) → brings it to **Happy** and resets its decay timer
- **Pet** an animal that is at least **Happy** → brings it to **Loving** (or resets its timer if already there)

### Scoring
Every animal that reaches or sustains **Loving** state contributes to your overall score. The more love you spread — and keep alive — the higher it climbs.

---

## Built With

- **C++17**
- **Raylib**

---

## Privacy

P&P collects no data. No accounts, no tracking, nothing. It is designed to be completely safe for children.

> *If multiplayer is ever added in the future, account creation will require only a valid email address — no other personal information.*

---

## Status

🚧 Early development
