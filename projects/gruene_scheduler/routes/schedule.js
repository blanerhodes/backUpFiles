const express = require("express"),
router = express.Router(),
Week = require("../models/week"),
testFunc =  require("../public/setSchedule"),
Employee = require("../models/employee");

// router.get("/schedule", (req, res) => {
//     Employee.find({}, (err, employees) => {
//         if(err) {
//             console.log(err);
//         } else {
//             res.render("scheduleTest", {employees:employees});
//         }
//     })
//})

//show the schedule
router.get("/schedule", (req, res) => {
    Employee.find({}, (err, employees) => {
        if(err) {
            console.log(err);
        } else {
            Week.find({}, (err, weeks) => {
                if(err) {
                    console.log(err);
                } else {
                    res.render("scheduleTest", {weeks:weeks, employees:employees});
                }
            })
        }
    })
});

//post request to update week busy-ness array
router.post("/week", (req, res) => {
    // req.body.week.body = req.sanitize(req.body.week.body);

    const week = new Week(req.body.week);
    console.log(week);
    Week.remove({}, (err, data) => {
        Week.create(week, (err, newWeek) => {
            if(err) {
                console.log(err);
            } else {
                console.log(`newWeek: ${newWeek}`);
                res.redirect("/employees");
            }
        })
    })
    
});

router.put("/week/:id", (req, res) => {
    req.body.week.body = req.sanitize(req.body.week.body);
    Week.findByIdAndUpdate(req.params.id, req.body.week, (err, updatedWeek) => {
        if(err) {
            // res.redirect("/employees");
            console.log(err);
        } else {
            res.redirect("/schedule");
        }
    })
})

router.get("/generate", async(req, res) => {
    
    try {
        await testFunc.doStuff();
        res.render("scheduleTest");
    } catch(err) {
        res.status(500).send();
    }
})

module.exports = router;