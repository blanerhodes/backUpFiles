const Employee       = require("../models/employee"),
      Week           = require("../models/week"),
      moment         = require("moment")
;

//access specific day of the days array with days[0][0].[day]
//access specific employee of emps array with emps[0][employeeIndex]

//FIGURE OUT HOW TO GIVE EVERY DAY AFTER MONDAY A DATE
async function getWeekInfo() {
    try {
        const week = await Week.findOne({});

        console.log(`week: ${week}`);
        const dates = Object.keys(week._doc)
            .filter(key => ['monday', 'tuesday', 'wednesday', 'thursday', 'friday', 'saturday', 'sunday'].includes(key))
            .map(key => week[key])
            .filter(dayOfWeek => dayOfWeek)
            .map(dayOfWeek => dayOfWeek.date)
            .filter(date => date)
            .map(date => moment(date));
        console.log(`dates from week: ${JSON.stringify(dates)}`);

        const scheduleByEmployee = await getEmployeeInfo(dates);
        console.log(`scheduleByEmployee: ${scheduleByEmployee}`);

    } catch (err) {
        console.log(err);
    }
}

async function getEmployeeInfo(dates) {
    const employees = await Employee.find({});
    const scheduleByEmployee = checkIfOff(employees, dates);
    return scheduleByEmployee;
}


//YOU WERE CHECKING HOW THE FOR LOOPS WERE PRINTING STUFF OUT HERE
function checkIfOff(employees, dates) {
    const trueDates = dates.map(date => `${moment(date).format('MM/DD/YYYY')}`);
    console.log(`trueDates: ${trueDates}`);

    const matchingDatesByEmployee = employees
        .map(employee => {
            const matchingDates = trueDates.filter(trueDate => employee.vacation && employee.vacation.includes(trueDate));
            return {
                employee,
                datesOff: matchingDates
            };
        });
    
    for (const employeeSchedule of matchingDatesByEmployee) {
        if (employeeSchedule.datesOff.length === 0) {
            console.log(`This week, ${employeeSchedule.employee.name} is working every day`);
        } else {
            console.log(`This week, ${employeeSchedule.employee.name} is off ${employeeSchedule.datesOff}`);
        }
    }

    return matchingDatesByEmployee;
}

// function fetchData() {
//     getEmpInfo();
//     getWeekInfo();
// }

function checkIfPrevNight() {

}

function checkIfWorkedToday() {

}

function checkQualify() {

}

function compareMinHours() {

}

function compareMaxHours() {

}

function testThis() {
    console.log(emps);
}

async function doStuff() {
    const returnValue = await getWeekInfo();

}

module.exports = {
    doStuff,
}