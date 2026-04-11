# solar-cleaner-web

Web interface for the solar cleaner machine. Static HTML/CSS/JS front-end backed by PHP endpoints that talk to a MySQL database to authenticate users and manage machines.

## Platform

- HTML, CSS, vanilla JavaScript front-end
- PHP + MySQL back-end

## What it does

- Login page authenticating against the `getUser.php` endpoint
- Dashboard with pages for the main view, controller, left track, right track and brush
- PHP API for creating, reading, updating and deleting machine records

## Layout

```
index.html          login page
html/               dashboard, controller and per-subsystem pages
css/                per-page stylesheets and var.css theme
js/                 per-page scripts
api/                PHP endpoints (getUser, getMachine, createMachine,
                    setMachine, deleteMachine) and apiExample.cpp
res/                logos and other assets
ui/                 CorelDRAW design sources
```

## Run

Serve the repository from a PHP-capable web host with a MySQL database reachable from the `api/*.php` scripts. Update the database credentials in the PHP files to match the target environment, then open `index.html` in a browser.
