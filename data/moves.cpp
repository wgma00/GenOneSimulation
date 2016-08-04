#include<bits/stdc++.h>
using namespace std;

auto Moves = map<string, map<string, string>{
    "earthquake": {
        "accuracy": 100,
        "basePower": 100,
        "category": "Physical",
        "pp": 10,
        "secondary": False,
        "target": "allAdjacent",
        "type": "Ground"
    },
    "bodyslam": {
        "accuracy": 100,
        "basePower": 85,
        "category": "Physical",
        "pp": 15,
        "secondary": {
            "chance": 30,
            "status": "par"
        },
        "target": "normal",
        "type": "Normal"
    },
    "rockslide": {
        "accuracy": 90,
        "basePower": 75,
        "category": "Physical",
        "pp": 10,
        "secondary": {
            "chance": 30,
            "volatileStatus": "flinch"
        },
        "target": "allAdjacentFoes",
        "type": "Rock"
    },
    "substitute": {
        "accuracy": True,
        "basePower": 0,
        "category": "Status",
        "pp": 10,
        "volatileStatus": "Substitute",
        "secondary": False,
        "target": "self",
        "type": "Normal"
    },
    "amnesia": {
        "accuracy": True,
        "basePower": 0,
        "category": "Status",
        "pp": 20,
        "boosts": {
            "spd": 2
        },
        "secondary": False,
        "target": "self",
        "type": "Psychic"
    },
    "rest": {
        "accuracy": True,
        "basePower": 0,
        "category": "Status",
        "pp": 10,
        "secondary": False,
        "target": "self",
        "type": "Psychic"
    },
    "thunderwave": {
        "accuracy": 100,
        "basePower": 0,
        "category": "Status",
        "pp": 20,
        "status": "par",
        "ignoreImmunity": False,
        "secondary": False,
        "target": "normal",
        "type": "Electric"
    },
    "surf": {
        "accuracy": 100,
        "basePower": 90,
        "category": "Special",
        "pp": 15,
        "secondary": False,
        "target": "allAdjacent",
        "type": "Water"
    },
    "selfdestruct": {
        "accuracy": 100,
        "basePower": 200,
        "category": "Physical",
        "pp": 5,
        "selfdestruct": True,
        "secondary": False,
        "target": "allAdjacent",
        "type": "Normal"
    },
    "counter": {
        "accuracy": 100,
        "basePower": 0,
        "category": "Physical",
        "pp": 20,

        "secondary": False,
        "target": "scripted",
        "type": "Fighting"
    },
    "hyperbeam": {
        "accuracy": 90,
        "basePower": 150,
        "category": "Special",
        "pp": 5,
        "self": {
            "volatileStatus": "mustrecharge"
        },
        "secondary": False,
        "target": "normal",
        "type": "Normal"
    },
    "thunderbolt": {

        "accuracy": 100,
        "basePower": 95,
        "category": "Special",
        "pp": 15,
        "secondary": {
            "chance": 10,
            "status": "par"
        },
        "target": "normal",
        "type": "Electric"
    },
    "drillpeck": {
        "accuracy": 100,
        "basePower": 80,
        "category": "Physical",
        "pp": 20,
        "secondary": False,
        "target": "any",
        "type": "Flying"
    },
    "agility": {
        "accuracy": True,
        "basePower": 0,
        "category": "Status",
        "pp": 30,
        "boosts": {
            "spe": 2
        },
        "secondary": False,
        "target": "self",
        "type": "Psychic"
    },
    "psychic": {
        "accuracy": 100,
        "basePower": 90,
        "category": "Special",
        "pp": 10,
        "secondary": {
            "chance": 10,
            "boosts": {
                "spd": -1
            }
        },
        "target": "normal",
        "type": "Psychic"
    },
    "recover": {
        "accuracy": True,
        "basePower": 0,
        "category": "Status",
        "pp": 10,
        "heal": [1, 2],
        "secondary": False,
        "target": "self",
        "type": "Normal"
    },
    "sing": {
        "accuracy": 55,
        "basePower": 0,
        "category": "Status",
        "pp": 15,
        "status": "slp",
        "secondary": False,
        "target": "normal",
        "type": "Normal"
    },
    "confuseray": {
        "accuracy": 100,
        "basePower": 0,
        "category": "Status",
        "pp": 10,
        "volatileStatus": "confusion",
        "secondary": False,
        "target": "normal",
        "type": "Ghost"
    },
    "doublekick": {
        "accuracy": 100,
        "basePower": 30,
        "category": "Physical",
        "pp": 30,
        "multihit": 2,
        "secondary": False,
        "target": "normal",
        "type": "Fighting"
    },
    "pinmissile": {
        "accuracy": 95,
        "basePower": 25,
        "category": "Physical",
        "pp": 20,
        "multihit": [2, 5],
        "secondary": False,
        "target": "normal",
        "type": "Bug"
    },
    "explosion": {
        "accuracy": 100,
        "basePower": 250,
        "category": "Physical",
        "pp": 5,
        "selfdestruct": True,
        "secondary": False,
        "target": "allAdjacent",
        "type": "Normal"
    },
    "hypnosis": {
        "accuracy": 60,
        "basePower": 0,
        "category": "Status",
        "pp": 20,
        "status": "slp",
        "secondary": False,
        "target": "normal",
        "type": "Psychic"
    },
    "nightshade": {
        "accuracy": 100,
        "basePower": 0,
        "damage": "level",
        "category": "Special",
        "pp": 15,
        "secondary": False,
        "target": "normal",
        "type": "Ghost"
    },
    "sleeppowder": {
        "accuracy": 75,
        "basePower": 0,
        "category": "Status",
        "pp": 15,
        "status": "slp",
        "secondary": False,
        "target": "normal",
        "type": "Grass"
    },
    "stunspore": {
        "accuracy": 75,
        "basePower": 0,
        "category": "Status",
        "pp": 30,
        "status": "par",
        "secondary": False,
        "target": "normal",
        "type": "Grass"
    },
    "doubleedge": {
        "accuracy": 100,
        "basePower": 120,
        "category": "Physical",
        "pp": 15,
        "recoil": [33, 100],
        "secondary": False,
        "target": "normal",
        "type": "Normal"
    },
    "megadrain": {
        "accuracy": 100,
        "basePower": 40,
        "category": "Special",
        "pp": 15,
        "drain": [1, 2],
        "secondary": False,
        "target": "normal",
        "type": "Grass"
    },
    "icebeam": {
        "accuracy": 100,
        "basePower": 90,
        "category": "Special",
        "pp": 10,
        "secondary": {
            "chance": 10,
            "status": "frz"
        },
        "target": "normal",
        "type": "Ice"
    },
    "reflect": {
        "accuracy": True,
        "basePower": 0,
        "category": "Status",
        "pp": 20,
        "sidecondition": "reflect",
        "secondary": False,
        "target": "allySide",
        "type": "Psychic"
    },
    "seismictoss": {
        "accuracy": 100,
        "basePower": 0,
        "damage": "level",
        "category": "Physical",
        "pp": 20,
        "secondary": False,
        "target": "normal",
        "type": "Fighting"
    },
    "clamp": {
        "accuracy": 85,
        "basePower": 35,
        "category": "Physical",
        "pp": 15,
        "volatileStatus": "partiallytrapped",
        "secondary": False,
        "target": "normal",
        "type": "Water"
    },
    "softboiled": {
        "accuracy": True,
        "basePower": 0,
        "category": "Status",
        "pp": 10,
        "heal": [1, 2],
        "secondary": False,
        "target": "self",
        "type": "Normal"
    }
}

int main() {
}
