const express  = require("express"),
app            = express(),
bodyParser     = require("body-parser"),
mongoose       = require("mongoose"),
sanitizer      = require("express-sanitizer"),
methodOverride = require("method-override"),
Employee       = require("./models/employee"),
Week           = require("./models/week"),
employeeRoutes = require("./routes/employees"),
scheduleRoutes = require("./routes/schedule"),
authRoutes     = require("./routes/authenticate"),
moment         = require("moment"),
db             = require("./config/keys").mongoURI,
setSchedule    = require("./public/setSchedule")
;

//app config 
mongoose
    .connect(db, {useNewUrlParser: true})
    .then(() => console.log('MongoDB Connected'))
    .catch(err => console.log(err));
app.set("view engine", "ejs");
app.use(express.static("public"));
app.use(bodyParser.urlencoded({extended: true}));
app.use(methodOverride("_method"));
app.use(sanitizer());

//BAND ROUTING
//new employee form
// app.get("/employees/new", (req,res) => {
//     res.render("newEmp");
// });



app.use(employeeRoutes);
app.use(scheduleRoutes);
app.use(authRoutes);

app.listen(3000, ()=> {
    console.log("SCHEDULE SERVER STARTED");
})


