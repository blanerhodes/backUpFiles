const mongoose = require("mongoose");

const weekSchema = new mongoose.Schema({
    monday: {
        date: String,
        degOfBusy: String,
        "8": [String],
        "9": [String],
        "10": [String],
        "13": [String],
        "15": [String],
        "17": [String],
        "18": [String],
        "19": [String],
        "20": [String],
        "21": [String]
    },
    tuesday: {
        date: String,
        degOfBusy: String,
        "8": [String],
        "9": [String],
        "10": [String],
        "13": [String],
        "15": [String],
        "17": [String],
        "18": [String],
        "19": [String],
        "20": [String],
        "21": [String]
        },
    wednesday: {
        date: String,
        degOfBusy: String,
        "8": [String],
        "9": [String],
        "10": [String],
        "13": [String],
        "15": [String],
        "17": [String],
        "18": [String],
        "19": [String],
        "20": [String],
        "21": [String]
    },
    thursday: {
        date: String, 
        degOfBusy: String,
        "8": [String],
        "9": [String],
        "10": [String],
        "13": [String],
        "15": [String],
        "17": [String],
        "18": [String],
        "19": [String],
        "20": [String],
        "21": [String]
    },
    friday: {
        date: String,
        degOfBusy: String,
        "8": [String],
        "9": [String],
        "10": [String],
        "13": [String],
        "15": [String],
        "17": [String],
        "18": [String],
        "19": [String],
        "20": [String],
        "21": [String]
    },
    saturday: {
        date: String,
        degOfBusy: String,
        "8": [String],
        "9": [String],
        "10": [String],
        "13": [String],
        "15": [String],
        "17": [String],
        "18": [String],
        "19": [String],
        "20": [String],
        "21": [String]
    },
    sunday: {
        date: String,
        degOfBusy: String,
        "8": [String],
        "9": [String],
        "10": [String],
        "13": [String],
        "15": [String],
        "17": [String],
        "18": [String],
        "19": [String],
        "20": [String],
        "21": [String]
    }
});

module.exports = mongoose.model("Week", weekSchema);