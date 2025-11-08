Deployment (free) — GitHub Pages / Vercel / Netlify

This project includes a ready-to-deploy static site in the `web/` folder. The site is plain HTML/CSS/JS and can be hosted for free.

Options:

1) GitHub Pages (recommended for static sites)
- Commit the `web/` folder to your repository (example: in repo root).
- Quick method (push `web/` to `gh-pages` branch):

  ```powershell
  git add web -A
  git commit -m "Add web UI for Doomculator"
  git push origin HEAD:gh-pages
  ```

  Then in your GitHub repo settings -> Pages, select `gh-pages` branch as source. The site will be live at:
  `https://<your-username>.github.io/<repo-name>/`

- Alternative: copy contents of `web/` into a `docs/` folder on the `main` branch. GitHub Pages can serve from `docs/`.

2) Netlify / Vercel (zero-config for static sites)
- Create an account on Netlify or Vercel and connect your GitHub repository. Set the build folder to `web/` (no build command needed).
- Or drag-and-drop the contents of the `web/` folder in Netlify's deploy UI.

3) Serve locally for testing
- Any static file server will work.

  ```powershell
  # Using Python (if installed)
  cd web
  python -m http.server 8000
  # then open http://localhost:8000
  ```

Notes and follow-ups
- If you want a custom domain, configure it in GitHub Pages / Netlify settings.
- I can create a GitHub Action to automatically publish `web/` on push to `main` if you want CI/CD.
- Tell me which hosting option you prefer and I can either prepare a GitHub Action or walk you through the exact steps.